/*
 * Created by Qt Creator 4.11.0 @ 24 Mar 2021 21:52:41
 *
 * Project: GB_CppOOP
 * File: task_1.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <string>
#include <sstream>
#include <cstring>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>

namespace task_1 {

// --------------------------------------------------------------------------------------
template <typename T>
class MyArray {
public:
  MyArray() = default;
  MyArray(std::size_t length);

  ~MyArray();

  MyArray(const std::initializer_list<T> &);

  T& operator[](std::size_t index);
  const T& operator[](std::size_t index) const;

  void erase();

  inline std::size_t getLength() const { return m_length; }
  void resize(std::size_t newLength);

  void insertBefore(T const &value, std::size_t index);
  void pushBack(T const &value);
  void popBack();
  void popFront();
  void sort();

  std::string toString(const std::string &separator = std::string{}) const;

private:
  std::size_t m_length {0u};
  T *m_data {nullptr};
};

// --------------------------------------------------------------------------------------
template <typename T>
MyArray<T>::MyArray(std::size_t length) {
  if (length > 0u) {
    m_data = new (std::nothrow) T[length];
    if (nullptr != m_data) {
      std::fill(m_data, m_data + length, T{});
      m_length = length;
    }
  }
}

// --------------------------------------------------------------------------------------
template <typename T>
MyArray<T>::~MyArray() { delete[] m_data; }

template <typename T>
MyArray<T>::MyArray(const std::initializer_list<T> &l) : MyArray<T>(l.size()) {
// здесь использована концепция делегирования конструкторов для создания и инициализации
// внутреннего массива m_data
  std::size_t n{0u};
  for (auto &element : l) {
    m_data[n++] = element;
  }
}

// --------------------------------------------------------------------------------------
template <typename T>
void MyArray<T>::erase() {
  delete[] m_data;
  m_data = nullptr;
  m_length = 0u;
}

// --------------------------------------------------------------------------------------
template <typename T>
T& MyArray<T>::operator[](std::size_t index) {
  assert(index < m_length);
  return m_data[index];
}

// --------------------------------------------------------------------------------------
template <typename T>
const T& MyArray<T>::operator[](std::size_t index) const {
  assert(index < m_length);
  return m_data[index];
}

// --------------------------------------------------------------------------------------
template <typename T>
void MyArray<T>::resize(std::size_t newLength) {
  if (newLength == m_length) return;

  if (0u == newLength) {
    erase();
    return;
  }

  T *data {new (std::nothrow) T[newLength]};
  if (nullptr != data) {
    if (m_length > 0u) {
      std::copy(m_data, m_data + m_length, data);
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
  }
}

// --------------------------------------------------------------------------------------
template <typename T>
void MyArray<T>::insertBefore(T const &value, std::size_t index) {
  assert(index <= m_length);

  T *data{new (std::nothrow) T[m_length + 1u]};
  if (nullptr != data) {
    for (std::size_t before{0u}; before < index; ++before) {
      data[before] = m_data[before];
    }
    data[index] = value;
    for (std::size_t after{index}; after < m_length; ++after) {
      data[after + 1u] = m_data[after];
    }
  }

  delete[] m_data;
  m_data = data;
  ++m_length;
}

// --------------------------------------------------------------------------------------
template <typename T>
void MyArray<T>::pushBack(T const &value) {
  insertBefore(value, m_length);
}

// --------------------------------------------------------------------------------------
template<typename T>
void MyArray<T>::popBack() {
  T *data {new (std::nothrow) T[m_length - 1u]};
  if (nullptr != data) {
    --m_length;
    std::copy(m_data, m_data + m_length, data);
    delete [] m_data;
    m_data = data;
  }
}

// --------------------------------------------------------------------------------------
template <typename T>
void MyArray<T>::popFront() {
  std::memmove(m_data, m_data + 1u, sizeof(T) * (m_length - 1u));
  popBack();
}

// --------------------------------------------------------------------------------------
template <typename T>
void MyArray<T>::sort() {
  static auto partition = [this](std::size_t n, std::size_t m) {
    const T &x{m_data[n]};
    std::size_t i{n};
    for (std::size_t j{n + 1u}; j < m; ++j) {
      if (m_data[j] <= x) {
        std::swap(m_data[++i], m_data[j]);
      }
    }
    std::swap(m_data[i], m_data[n]);
    return i;
  };

  std::function<void(std::size_t, std::size_t)> quickSort;
  quickSort = [&quickSort](std::size_t n, std::size_t m) {
    if (n < m) {
      auto i = partition(n, m);
      quickSort(n, i);
      quickSort(i + 1u, m);
    }
  };

  quickSort(0u, m_length);
}

// --------------------------------------------------------------------------------------
template<typename T>
std::string MyArray<T>::toString(const std::string &separator) const {
  std::ostringstream ss;
  if (m_length > 0) {
    ss << m_data[0u];
    for (std::size_t n {1u}; n < m_length; ++n) {
      ss << separator << m_data[n];
    }
  }
  return ss.str();
}

} // namespace task_1

