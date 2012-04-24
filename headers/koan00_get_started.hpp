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

#ifndef KOAN00_GET_STARTED_HPP
#define KOAN00_GET_STARTED_HPP

using namespace std;

class Koan00_get_started
{
  private:
    static const int num_tests = 1;
    int num_passed;
    int num_failed;

  public:
    Koan00_get_started() : num_passed(0), num_failed(0) {}
    ~Koan00_get_started() {}

    int run() {
      num_passed = num_failed = 0;
      
      cpp_is_not_too_hard();
      num_passed++;

      return num_passed;
    }

    static int get_num_tests() {
      return num_tests;
    }

  private:
    void cpp_is_not_too_hard();
};

#endif // KOAN00_GET_STARTED_HPP

// EOF