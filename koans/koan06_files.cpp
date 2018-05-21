/*
    Copyright (c) 2012 Torbjörn Klatt <opensource@torbjoern-klatt.de>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

#include "../headers/koan06_files.hpp"

// The implementations of the different koans of this episode is done here.
// Don't forget to rename the above include.

void Koan06_files::they_are_accessed_using_file_pointers() {
  FILE *fp = 0;

  fp = fopen("../koans/file_exists.txt", "r");
  ASSERT(fp != 0);

  fp = fopen("../koans/nonexistentfile", "r");
  ASSERT_EQUAL(fp, FILL_THE_NUMBER_IN);

  if (fp)
    fclose(fp);
}
void Koan06_files::they_can_be_used_to_store_information() {
  int marks[10] = {38, 54, 93, 41, 55, 86, 59, 100, 40, 92};

  //------------------
  // typical file operations to store 'database' marks in file
  FILE *fp = fopen("data.bin", "w+b");
  fwrite(marks, 10, sizeof(int), fp);
  // fseek(fp, 0L, SEEK_SET);
  int filesize = ftell(fp);
  fclose(fp);
  //------------------

  // Is 'filesize' the same as size of marks database?
  ASSERT_EQUAL(filesize, FILL_THE_NUMBER_IN);
  // And what is the actual size of the file?
  ASSERT_EQUAL(filesize, FILL_THE_NUMBER_IN);
}

#include <string.h>

void Koan06_files::they_can_be_used_for_retrieval() {
  int marks[10];
  memset(marks, 0, 10 * sizeof(int));
  int sum = 0;
  for (int i = 0; i < 10; i++)
    sum += marks[i];
  ASSERT_EQUAL(sum, 0);

  FILE *fp = fopen("data.bin", "r+b");
  fread(marks, 10, sizeof(int), fp);
  // marks[10] = {38, 54, 93, 41, 55, 86, 59, 100, 40, 92};
  for (int i = 0; i < 10; i++)
    sum += marks[i];

  ASSERT_EQUAL(sum, FILL_THE_NUMBER_IN);
}

// EOF
