#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[]) {
  size_t size = 100;
  char *line = (char *)calloc(size + 1, sizeof(char));
  if (line == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  while (fgets(line, size, stdin) != NULL) {
    line[strcspn(line, "\n")] = '\0';  // Remove newline if present
    char *pd = palindrome(line);
    if (pd != NULL) {
      printf("Is the string <%s> a palindrome? %s\n", line, pd);
      free(pd);
    } else {
      fprintf(stderr, "Palindrome check failed for input: %s\n", line);
    }
  }

  free(line);
  return 0;
}
