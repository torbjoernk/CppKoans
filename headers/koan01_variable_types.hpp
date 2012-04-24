/*
    Copyright (c) 2012 <copyright holder> <email>

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

#include "../helper.hpp"

#ifndef KOAN01_VARIABLE_TYPES_HPP
#define KOAN01_VARIABLE_TYPES_HPP

class Koan01_variable_types
{
  private:
    static const int num_tests = 8;
    int num_passed;
    int num_failed;

  public:
    Koan01_variable_types() : num_passed(0), num_failed(0) {}
    virtual ~Koan01_variable_types() {}

    int run() {
      num_passed = num_failed = 0;

      simple_integer_numbers();
      num_passed++;

      integers_have_a_size();
      num_passed++;

      integers_can_be_negative();
      num_passed++;

      simple_floats();
      num_passed++;

      floats_have_a_size();
      num_passed++;

      going_double_precision();
      num_passed++;

      doubles_have_a_size();
      num_passed++;

      size_of_biggest_number();
      num_passed++;
      
      return num_passed;
    }

    static int get_num_tests() {
      return num_tests;
    }

  private:
    void simple_integer_numbers();
    void integers_have_a_size();
    void integers_can_be_negative();
    void simple_floats();
    void floats_have_a_size();
    void going_double_precision();
    void doubles_have_a_size();
    void size_of_biggest_number();
};

#endif // KOAN01_VARIABLE_TYPES_HPP

// EOF