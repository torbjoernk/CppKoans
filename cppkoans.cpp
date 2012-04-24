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

#include <iostream>
#include "headers/all_koans.hpp"

using namespace std;

int total_num_koans;    //!
int total_num_passed;   //!

/**
 *
 */
void print_status();

/**
 *
 */
int main()
{
  total_num_koans = 0;
  total_num_passed = 0;
  // Koan 00: getting started
  Koan00_get_started koan00 = Koan00_get_started();
  total_num_koans += koan00.get_num_tests();
  // Koan 01: variable types
  Koan01_variable_types koan01 = Koan01_variable_types();
  total_num_koans += koan01.get_num_tests();

  // The Path of Enlightment
  total_num_passed += koan00.run();
  cout << "Congratulations! You managed the first koans!" << endl;
  print_status();
  
  total_num_passed += koan01.run();

  // Done.
  return(0);
}


void print_status()
{
  cout << "You mastered " << total_num_passed << " koans." << endl
       << "There are " << (total_num_koans-total_num_passed)
       << " further koans on your path to enlightment." << endl
       << "Keep on going." << endl;
}


// EOF