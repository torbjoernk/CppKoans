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

#ifndef FILL_ME_IN_HPP
#define FILL_ME_IN_HPP

using namespace std;

class FillMeIn
{
  public:
    string file;
    int line;
    string msg;
    FillMeIn( const string f, const int l, string s ) : file( f ), line( l ), msg( s ) {
      file = file.substr( file.find_last_of( "/" ) + 1 );
    }
    ~FillMeIn() {}
};

#define ASSERT_MSG(expr, msg) do {                \
    if (!(expr))                                    \
    {                                               \
      throw FillMeIn(__FILE__, __LINE__, msg);      \
    };                                              \
  } while(0)

#define ASSERT(expr) ASSERT_MSG(expr, "")

#endif
