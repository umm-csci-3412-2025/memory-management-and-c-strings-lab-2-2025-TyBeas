#include <string.h>
#include <stdlib.h>

#include "disemvowel.h"

int vowelCounter(char *str) {
  int i, numVowels = 0;
  char *vowels = (char*)calloc(11, sizeof(char));
  strcpy(vowels, "aeiouAEIOU\0");
  int len = strlen(str);
  for (i = 0; i < len; i++) {
    if (strchr(vowels, str[i]) != NULL) {
      numVowels++;
    }
  }
  free(vowels);
  return numVowels;
}

char *disemvowel(char *str) {
  int length, numVowels, i, j = 0;
  char *results;
  char *vowels = (char*)calloc(11, sizeof(char));
  strcpy(vowels, "aeiouAEIOU\0");

  numVowels = vowelCounter(str);  // Use vowelCounter to get the number of vowels
  length = strlen(str);
  results = (char*)calloc(length - numVowels + 1, sizeof(char));

  for (i = 0; i < length; i++) {
    if (strchr(vowels, str[i]) == NULL) {
      results[j] = str[i];
      j++;
    }
  }
  results[length - numVowels] = '\0';
  free(vowels);
  return results;
}