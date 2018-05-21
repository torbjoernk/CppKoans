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

#include "../helper.hpp"

#ifndef KOAN05_POINTERS_HPP
#define KOAN05_POINTERS_HPP

// Rename the Episode
class Koan05_pointers : Koan {
private:
  KoanHandler *status;             //!
  static const int num_tests = 13; //!

public:
  /**
 *
 */
  Koan05_pointers(KoanHandler *status) : status(status) {
    status->register_koans(num_tests);
  }
  /**
 *
 */
  ~Koan05_pointers() {}

  /**
 *
 */
  void run() {
    status->episode_start("sixth");

    status->eval_koan(*this, static_cast<void (Koan::*)()>(
                                 &Koan05_pointers::they_are_just_variables));
    status->eval_koan(*this,
                      static_cast<void (Koan::*)()>(
                          &Koan05_pointers::they_are_really_just_variables));
    status->eval_koan(*this, static_cast<void (Koan::*)()>(
                                 &Koan05_pointers::they_have_power));
    status->eval_koan(*this, static_cast<void (Koan::*)()>(
                                 &Koan05_pointers::they_are_not_almighty));
    status->eval_koan(
        *this,
        static_cast<void (Koan::*)()>(
            &Koan05_pointers::they_can_be_non_const_unlike_array_variables));
    status->eval_koan(*this, static_cast<void (Koan::*)()>(
                                 &Koan05_pointers::they_can_manipulate_arrays));
    status->eval_koan(
        *this,
        static_cast<void (Koan::*)()>(
            &Koan05_pointers::they_can_be_assigned_addresses_and_pValues));
    status->eval_koan(
        *this,
        static_cast<void (Koan::*)()>(
            &Koan05_pointers::they_can_do_arithmetic_with_integers_only));
    status->eval_koan(
        *this,
        static_cast<void (Koan::*)()>(
            &Koan05_pointers::they_can_be_initialized_to_dynamic_memory));
    status->eval_koan(
        *this,
        static_cast<void (Koan::*)()>(
            &Koan05_pointers::they_can_be_used_to_access_dynamic_memory));
    status->eval_koan(
        *this,
        static_cast<void (Koan::*)()>(
            &Koan05_pointers::they_are_required_if_you_want_to_write_swap));
    status->eval_koan(
        *this,
        static_cast<void (Koan::*)()>(
            &Koan05_pointers::they_are_used_as_function_arguments_parameters));
    status->eval_koan(
        *this,
        static_cast<void (Koan::*)()>(
            &Koan05_pointers::they_are_used_for_writing_indirection_code));

    status->episode_done("sixth");
  }

  /**
 *
 */
  static int get_num_tests() { return num_tests; }

private:
  // REMARK: Do not forget to increase this.num_tests when you add another
  // koan
  void they_are_just_variables();
  void they_are_really_just_variables();
  void they_have_power();
  void they_are_not_almighty();
  void they_can_be_non_const_unlike_array_variables();
  void they_can_manipulate_arrays();
  void they_can_be_assigned_addresses_and_pValues();
  void they_can_do_arithmetic_with_integers_only();
  void they_can_be_initialized_to_dynamic_memory();
  void they_can_be_used_to_access_dynamic_memory();
  void they_are_required_if_you_want_to_write_swap();
  void they_are_used_as_function_arguments_parameters();
  void they_are_used_for_writing_indirection_code();
};

#endif // KOAN05_POINTERS_HPP

// EOF
