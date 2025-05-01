#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "disemvowel.h"

int vowelCounter(char *str) {
    int i, numVowels = 0;
    const char *vowels = "aeiouAEIOU";
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (strchr(vowels, str[i]) != NULL) {
            ++numVowels;
        }
    }
    return numVowels;
}

char *disemvowel(char *str) {
    int length, vow, i, j = 0;
    char *results;
    const char *vowels = "aeiouAEIOU";

    vow = vowelCounter(str);
    length = strlen(str);
    results = (char *)calloc(length - vow + 1, sizeof(char));

    for (i = 0; i < length; ++i) {
        if (strchr(vowels, str[i]) == NULL) {
            results[j++] = str[i];
        }
    }

    results[j] = '\0';
    return results;
}