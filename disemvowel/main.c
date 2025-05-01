#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line = NULL;
  size_t size = 0;
  char *word;

  while (getline(&line, &size, stdin) > 0) {
    word = disemvowel(line);
    printf("%s\n", word);
    free(word);
  }

  free(line);
  return 0;
}
