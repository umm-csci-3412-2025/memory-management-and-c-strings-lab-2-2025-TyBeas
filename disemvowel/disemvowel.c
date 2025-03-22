#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "disemvowel.h"

const char* VOWELS = "aeiouAEIOU";

bool notVowel(char c) {
  for (int i = 0; i < 10; i++) {
    if (c == VOWELS[i]) {
      return false;
    }
  }
  return true;
}

char *disemvowel(char *str) {
  int notVowelCount = 0;
  int length = strlen(str);
  char* disemvowel = (char*) calloc(length + 1, sizeof(char));
  
  for (int i = 0; i < length; i++) {
    if (notVowel(str[i])) {
      disemvowel[notVowelCount] = str[i];
      notVowelCount++;
    }
  }
  disemvowel[notVowelCount] = '\0';
  return disemvowel;
}