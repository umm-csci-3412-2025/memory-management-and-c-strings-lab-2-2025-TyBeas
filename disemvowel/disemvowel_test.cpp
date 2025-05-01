#include <gtest/gtest.h>
#include <stdlib.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *word = disemvowel((char*) "");
  ASSERT_STREQ("", word);
  free(word);
}

TEST(Disemvowel, HandleNoVowels) {
  char *word = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", word);
  free(word);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *word = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", word);
  free(word);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *word = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", word);
  free(word);
}

TEST(Disemvowel, HandlePunctuation) {
  char *word = disemvowel((char*) "n (an explanation) elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", word);
  free(word);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  char *word;
  int size = 50000;
  int i;

  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size - 1; ++i) {
    str[i] = 'a';  // fill rest with vowels
  }
  str[size - 1] = '\0';

  word = disemvowel(str);
  ASSERT_STREQ("xyz", word);

  free(word);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
