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


#include "../headers/koan01_variable_types.hpp"

void Koan01_variable_types::simple_integer_numbers()
{
  int an_integer = 42;
  assert( an_integer == FILL_THE_NUMBER_IN );
}

void Koan01_variable_types::integers_have_a_size()
{
  int an_integer = 1;
  assert( sizeof( int ) == FILL_THE_NUMBER_IN );
  assert( sizeof( an_integer ) == FILL_THE_NUMBER_IN );
}

void Koan01_variable_types::integers_can_be_negative()
{
  int an_integer = 42;
  int another_integer = -42;
  assert( an_integer < another_integer );
}

void Koan01_variable_types::simple_floats()
{
  float a_float = 4.2;
  assert( a_float == FILL_THE_NUMBER_IN );
}

void Koan01_variable_types::floats_have_a_size()
{
  int a_float = 4.2;
  assert( sizeof( float ) == FILL_THE_NUMBER_IN );
  assert( sizeof( a_float ) == FILL_THE_NUMBER_IN );
}

void Koan01_variable_types::going_double_precision()
{

}

void Koan01_variable_types::doubles_have_a_size()
{

}

void Koan01_variable_types::size_of_biggest_number()
{
  // Remember: The size of long doubles vary from system to system.
  long double a_long_double = 4.2;
  // How big is it on your system?
  assert( sizeof( long double ) == FILL_THE_NUMBER_IN );
  assert( sizeof( a_long_double ) == FILL_THE_NUMBER_IN );
}


// EOF
