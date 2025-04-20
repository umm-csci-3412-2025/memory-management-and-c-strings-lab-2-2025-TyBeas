#include <string.h>
#include <stdlib.h>

#include "disemvowel.h"

int vowelCounter(char *str){
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
  int length, vowels, i, j;
  char *results;
  char* vowels = (char*)calloc(11, sizeof(char));
  strcpy(vowels, "aeiouAEIOU\0");

  vowels = vowelCounter(str);
  length = strlen(str);
  results = (char*)calloc(length - vowels + 1, sizeof(char));

  for (i = 0; i < length; i++) {
    if (strchr(vowels, str[i]) == NULL) {
      results[j] = str[i];
      j++;
    }
  }
  results[length - vowels] = '\0';
  free(vowels);
  return results;
}