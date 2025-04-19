#include <gtest/gtest.h>

#include "disemvowel.h"

char *word;

TEST(Disemvowel, HandleEmptyString) {
  ASSERT_STREQ("", word = disemvowel((char*) ""));
  free(word);
}

TEST(Disemvowel, HandleNoVowels) {
  ASSERT_STREQ("pqrst", word = disemvowel((char*) "pqrst"));
  free(word);
}

TEST(Disemvowel, HandleOnlyVowels) {
  ASSERT_STREQ("", word = disemvowel((char*) "aeiouAEIOUOIEAuoiea"));
  free(word);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  ASSERT_STREQ("Mrrs, Mnnst", word = disemvowel((char*) "Morris, Minnesota"));
  free(word);
}

TEST(Disemvowel, HandlePunctuation) {
  ASSERT_STREQ("n (nxplnd) lphnt!", word = disemvowel((char*) "n (an explanation) elephant!"));
  free(word);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char* result = disemvowel(str);
  free(word)
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
