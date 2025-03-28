#pragma once

#include <variant>
#include <exception>
#include <string>

class ResultException : public std::exception {
  public:
    ResultException(const char* message): message_(message) {}
    ResultException(const std::string& message): message_(message.c_str()) {}
    const char* what() const noexcept override;
  private:
    const char* message_;
};

// T - type of value
// E - type of error
// If T == E => UB
template <typename T, typename E>
class Result {
  public:
    enum class ResultType {
      Ok,
      Error
    };

    Result(T& value) 
      : m_value(std::move(value)) {}
    Result(T&& value) 
      : m_value(std::move(value)) {}

    Result(E&& error)
      : m_value(std::move(error)) {}

    constexpr bool is_error() const noexcept {
      return std::holds_alternative<E>(m_value);
    }
    constexpr bool is_ok() const noexcept { 
      return std::holds_alternative<T>(m_value);
    }

    const T& operator*() const {
      if (std::holds_alternative<E>(m_value)) {
        throw ResultException(error().message());
      }
      return std::get<T>(m_value);
    }

    /*
    Unwraps the Result and returns the contained value.
    If the Result is not an error, it will throw the exception.
    */
    const E error() const {
      if (std::holds_alternative<T>(m_value)) {
          throw ResultException("Object is not error");
      }
      return std::get<E>(m_value);
    }

    const T unwrap() const {
      if (std::holds_alternative<E>(m_value)) {
          throw ResultException(error().message());
      }
      return std::get<T>(m_value);
    }

    const T except(std::string&& message) const {
      if (std::holds_alternative<E>(m_value)) {
          throw ResultException(message);
      }
      return std::get<T>(m_value);
    }

    /*
    Returns Ok if the Result contains a value, Error otherwise.
    */
  constexpr ResultType type() const noexcept {
    return (std::holds_alternative<T>(m_value) ? ResultType::Ok : ResultType::Error);
  }

  private:
    std::variant<T, E> m_value;
};