#pragma once

#include "result.hpp"

enum class EnumError {
  //...
};

class StructError {
  public:
    StructError(const EnumError&& type, const std::string&& message)
      : m_type(type), m_message(message) {}
    StructError(const EnumError&& type)
      : m_type(type), m_message("No information") {}

    EnumError type() const noexcept;
    const std::string& message() const noexcept;

  private:
    EnumError m_type;
    std::string m_message;
};

template <typename T>
using UResult = Result<T, StructError>;