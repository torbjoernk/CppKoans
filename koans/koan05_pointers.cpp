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

#include "../headers/koan05_pointers.hpp"

void Koan05_pointers::they_are_just_variables() {
  int an_int = 42;
  int *pointer_to_an_int = &an_int;
  ASSERT_EQUAL(*pointer_to_an_int, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(pointer_to_an_int, THIS_IS_NOT_NULL);
}

void Koan05_pointers::they_are_really_just_variables() {
  int an_int = 42;
  int another_int = 21;
  int *pointer_to_an_int = &an_int;
  ASSERT_EQUAL(*pointer_to_an_int, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(pointer_to_an_int, THIS_IS_NOT_NULL);
  pointer_to_an_int = &another_int;
  ASSERT_EQUAL(*pointer_to_an_int, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(pointer_to_an_int, THIS_IS_NOT_NULL);
}

void Koan05_pointers::they_have_power() {
  int an_int = 42;
  int *powerful_pointer = &an_int;
  ASSERT_EQUAL(*powerful_pointer, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(powerful_pointer, THIS_IS_NOT_NULL);
  *powerful_pointer = 21;
  ASSERT_EQUAL(an_int, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(powerful_pointer, THIS_IS_NOT_NULL);
}

void Koan05_pointers::they_are_not_almighty() {
  const int an_int = 42;
  const int *wannabe_powerful = &an_int;
  ASSERT_EQUAL(*wannabe_powerful, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(wannabe_powerful, THIS_IS_NOT_NULL);
  // Will this work? Think about it!
  // What do you need to change to make it work?
  //   *wannabe_powerful = 21;
  ASSERT_EQUAL(an_int, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(wannabe_powerful, THIS_IS_NOT_NULL);
}

void Koan05_pointers::they_can_be_non_const_unlike_array_variables() {
  int array[4];
  int *pa = array;
  ASSERT_EQUAL(pa, THIS_IS_NOT_NULL);

  pa = pa + 3;
  ASSERT_EQUAL(pa, THIS_IS_NOT_NULL);
}

void Koan05_pointers::they_can_manipulate_arrays() {
  int array[4] = {1, 2, 3, 4};
  int *pa = array;
  ASSERT_EQUAL(*(pa + 2), FILL_THE_NUMBER_IN);
}

void Koan05_pointers::they_can_be_assigned_addresses_and_pValues() {
  int b;
  int *pA;
  int *pB = &b;
  pA = pB;
  ASSERT_EQUAL(*pA, FILL_THE_NUMBER_IN);
}

void Koan05_pointers::they_can_do_arithmetic_with_integers_only() {
  int a[10] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  a[5] = {8901};
  int *ap = a;

  // Do the necessary pointer arithmetic with ap
  ASSERT_EQUAL(&a[5], THIS_IS_NOT_NULL);
  // What is the value pointed to by ap before
  // and after the arithmetic?
  ASSERT_EQUAL(*ap, FILL_THE_NUMBER_IN);
  ap = ap + 5;
  ASSERT_EQUAL(*ap, FILL_THE_NUMBER_IN);
  ap = ap + 1;
  ASSERT_EQUAL(*ap, FILL_THE_NUMBER_IN);
}

void Koan05_pointers::they_can_be_initialized_to_dynamic_memory() {
  char *p = 0;
  p = (char *)malloc(5 * sizeof(char));
  ASSERT_EQUAL(p, THIS_IS_NOT_NULL);
}

void Koan05_pointers::they_can_be_used_to_access_dynamic_memory() {
  char *p = 0;
  p = (char *)malloc(5 * sizeof(char));
  *p = 'a';
  ASSERT_EQUAL(*p, FILL_THE_CHAR_IN);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Koan05_pointers::they_are_required_if_you_want_to_write_swap() {
  int a = 5;
  int b = 3;
  swap(&a, &b);

  ASSERT_EQUAL(a, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(b, FILL_THE_NUMBER_IN);
}

void g(int x, int *y) {
  printf("In g, x = %d, *y = %d\n", x, *y);
  x++;
  *y = *y - x;
  y = &x;
}

void fg(int *a, int b) {
  printf("In fg, *a = %d, b = %d\n", *a, b);
  *a += b;
  b *= 2;
  g(*a, &b);
  printf("Back in fg, *a = %d, b = %d\n", *a, b);
}

void Koan05_pointers::they_are_used_as_function_arguments_parameters() {
  int x = 3;
  int y = 4;
  fg(&x, y);
  printf("In main: x = %d, y = %d\n", x, y);

  ASSERT_EQUAL(x, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(y, FILL_THE_NUMBER_IN);
}

int f(int **r, int **s) {
  int temp = **r;
  int temp2 = **s;
  int *z = *r;
  *r = *s;
  *s = z;
  // printf("**r = %d\n",**r);
  // printf("**s = %d\n",**s);
  *z += 3;
  **s -= 8;
  **r -= 19;
  return temp + temp2;
}

void Koan05_pointers::they_are_used_for_writing_indirection_code() {
  int a = 80;
  int b = 12;
  int *p = &a;
  int *q = &b;
  int x = f(&p, &q);
  ASSERT_EQUAL(a, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(b, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(x, FILL_THE_NUMBER_IN);
}

// EOF
