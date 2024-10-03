#ifndef STD_DARRAY_H
#define STD_DARRAY_H

#include <stdlib.h>

#define DEFINE_DARRAY(type)                                               \
                                                                          \
typedef struct {                                                          \
  size_t capacity;                                                        \
  size_t length;                                                          \
  type* data;                                                             \
} DArray_##type;                                                          \
                                                                          \
void _ERR##type() {                                                       \
  fprintf(stderr, "ERROR: Memory Allocation Failed!\n");                  \
  exit(EXIT_FAILURE);                                                     \
}                                                                         \
                                                                          \
DArray_##type* darray_init_##type() {                                     \
  DArray_##type* darr = (DArray_##type*)malloc(sizeof(DArray_##type));    \
  if (!darr) _ERR##type();                                                \
  darr->capacity = 1;                                                     \
  darr->length = 0;                                                       \
  darr->data = (type*)malloc(darr->capacity * sizeof(type));              \
  if (!darr->data) _ERR##type();                                          \
  return darr;                                                            \
}                                                                         \
                                                                          \
void darray_push_back_##type(DArray_##type* darr, type value) {           \
  if (darr->length >= darr->capacity) {                                   \
    darr->capacity *= 2;                                                  \
    darr->data = realloc(darr->data, darr->capacity * sizeof(type));      \
  }                                                                       \
  if (!darr->data) _ERR##type();                                          \
  darr->data[darr->length++] = value;                                     \
}                                                                         \
                                                                          \
void darray_resize_##type(DArray_##type* darr, size_t newsize) {          \
  if (newsize <= 0) return;                                               \
  darr->capacity = newsize;                                               \
  darr->data = realloc(darr->data, darr->capacity * sizeof(type));        \
  if (!darr->data) _ERR##type();                                          \
}                                                                         \
                                                                          \
void darray_reverse_##type(DArray_##type* darr) {                         \
  for (int i = 0; i < darr->length-i; i++) {                              \
    type temp = darr->data[i];                                            \
    darr->data[i] = darr->data[darr->length-i-1];                         \
    darr->data[darr->length-i-1] = temp;                                  \
  }                                                                       \
}                                                                         \
                                                                          \
void darray_shrink_to_fit_##type(DArray_##type* darr) {                   \
  darr->capacity = darr->length;                                          \
  darr->data = realloc(darr->data, darr->capacity * sizeof(type));        \
  if (!darr->data) _ERR##type();                                          \
}                                                                         \
                                                                          \
type darray_front_##type(DArray_##type* darr) {                           \
  return darr->data[0];                                                   \
}                                                                         \
                                                                          \
type darray_back_##type(DArray_##type* darr) {                            \
  return darr->data[darr->length-1];                                      \
}                                                                         \
                                                                          \
void darray_pop_out_##type(DArray_##type* darr) {                         \
  if (darr->length == 0) return;                                          \
  darr->length--;                                                         \
}                                                                         \
                                                                          \
void darray_destroy_##type(DArray_##type* darr) {                         \
  if (darr) {                                                             \
    free(darr->data);                                                     \
    free(darr);                                                           \
  }                                                                       \
}                                                                         \

#endif
