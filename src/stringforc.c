#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringforc.h"

// Функция для создания строки
String createString(const char* str) {
  String s;
  s.length = strlen(str);
  s.data = (char*)malloc(s.length + 1); // +1 для нуль-терминатора
  if (s.data) {
    strcpy(s.data, str);
  }
  return s;
}

// Функция для освобождения памяти
void freeString(String* s) {
  free(s->data);
  s->data = NULL; // Обнуляем указатель после освобождения памяти
  s->length = 0;  // Сбрасываем длину
}

// Функция для получения длины строки
size_t stringLength(const String* s) {
  return s->length;
}

// Функция для конкатенации строк
String stringConcat(const String* s1, const String* s2) {
  String result;
  result.length = s1->length + s2->length;
  result.data = (char*)malloc(result.length + 1); // +1 для нуль-терминатора
  if (result.data) {
    strcpy(result.data, s1->data);
    strcat(result.data, s2->data);
  }
  return result;
}

// Функция для получения указателя на данные
const char* stringCStr(const String* s) {
  return s->data;
}

void assignString(String* s, const char *str) {
  s->length = strlen(str);
  free(s->data);
  s->data = (char *)malloc(s->length + 1);
  if (s->data) {
    strcpy(s->data, str);
  }
}