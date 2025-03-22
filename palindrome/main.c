#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[]) {
  char *line;
  int size;
  
  size = 100;
  line = (char*) calloc (size + 1, sizeof(char));

  while (fgets(line, size, stdin) != NULL) {
    line[strcspn(line, "\n")] = '\0';
    char *result = palindrome(line);
    printf("Is the string <%s> a palindrome? %s\n", line, palindrome(line));
    free((char*) result);
  }

  free(line);
}
