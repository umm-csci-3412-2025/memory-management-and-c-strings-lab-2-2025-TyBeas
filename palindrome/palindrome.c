#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "palindrome.h"

char *str_reverse(char const *str) {
  int length = strlen(str);
  char *result = (char *)calloc(length + 1, sizeof(char));
  
  if (result == NULL) return NULL;

  for (int i = 0; i < length; ++i) {
    result[i] = str[length - i - 1];
  }

  return result;
}

char *palindrome(char const *str) {
  char *rev = str_reverse(str);
  if (rev == NULL) return NULL;

  bool is_palindrome = (strcmp(str, rev) == 0);
  free(rev);

  return strdup(is_palindrome ? "Yes" : "No");
}
