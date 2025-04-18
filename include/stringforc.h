#pragma once

#include <stdint.h>

typedef struct {
  char* data;        // Указатель на массив символов
  size_t length;     // Длина строки
} String;

// Функция для создания строки
String createString(const char* str);

// Функция для освобождения памяти
void freeString(String* s);

// Функция для получения длины строки
size_t stringLength(const String* s);

// Функция для конкатенации строк
String stringConcat(const String* s1, const String* s2);

// Функция для получения указателя на данные
const char* stringCStr(const String* s);

void assignString(String* s, const char *str);