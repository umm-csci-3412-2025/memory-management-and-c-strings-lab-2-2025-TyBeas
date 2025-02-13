#include <stdlib.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  char *result;
  int len, pos;

  pos=0;
  len = strlen(str);
  result = (char*) calloc(len+1, sizeof(char));

  for (int i=0; i<len; ++i) {
    if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
      result[pos] = str[i];
      ++pos;
    }
  }
  result[len] = '\0';
  return result;
}
