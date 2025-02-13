#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line, *result;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);

  while (getline(&line, &size, stdin) > 0) {
    result = disemvowel(line);
    printf("%s\n", disemvowel(line));
    free(result);
  }
  free(line);
}
