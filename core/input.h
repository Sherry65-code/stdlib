#ifndef STD_INPUT_H
#define STD_INPUT_H

#include <stdio.h>
#include <string.h>
#include "return.h"

STD_RETURN get_int(const char* prompt, int* value) {
  if (prompt == NULL || value == NULL) return STD_FAILURE;

  printf("%s", prompt);
  int ret = fscanf(stdin, "%d", value);

  switch (ret) {
    case 0:
      scanf("%*[^\n]");
      getchar();
      return STD_FAILURE;
    case EOF:
      scanf("%*[^\n]");
      getchar();
      return STD_EOF;
    default:
      scanf("%*[^\n]");
      getchar();
      break;
  };

  return STD_SUCCESS;
}

STD_RETURN get_char(const char* prompt, char* value) {
  if (prompt == NULL || value == NULL) return STD_FAILURE;

  printf("%s", prompt);
  int ret = fscanf(stdin, "%c", value);

  switch (ret) {
    case 0:
      scanf("%*[^\n]");
      getchar();
      return STD_FAILURE;
    case EOF:
      scanf("%*[^\n]");
      getchar();
      return STD_EOF;
    default:
      scanf("%*[^\n]");
      getchar();
      break;
  };

  return STD_SUCCESS;
}

STD_RETURN get_float(const char* prompt, float* value) {
  if (prompt == NULL || value == NULL) return STD_FAILURE;

  printf("%s", prompt);
  int ret = fscanf(stdin, "%f", value);

  switch (ret) {
    case 0:
      scanf("%*[^\n]");
      getchar();
      return STD_FAILURE;
    case EOF:
      scanf("%*[^\n]");
      getchar();
      return STD_EOF;
    default:
      scanf("%*[^\n]");
      getchar();
      break;
  };

  return STD_SUCCESS;
}

STD_RETURN get_string(const char* prompt, char* buffer, int bufferSize) {
  if (prompt == NULL || buffer == NULL || bufferSize < 0) return STD_FAILURE;

  printf("%s", prompt);

  if (fgets(buffer, bufferSize, stdin) != NULL) {
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
      buffer[len-1] = '\0';
  } else {
    return STD_FAILURE;
  }

  return STD_SUCCESS;
}



#endif
