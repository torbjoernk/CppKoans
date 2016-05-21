/*
    Copyright (c) 2016 Thibauld Nion <thibauld@tibonihoo.net>

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

#include "../headers/koan10_auto.hpp"
#include <vector>
#include <type_traits>

// The following 'incomplete' class, triggers compile errors that shows you the most precise type information you can get. 
// See Scott Meyer's Effetive Modern C++ for details on this "Type Displayer" trick.
// HINT: instanciate it in the following koans to get some insight.
template<typename T>
class TD;


void Koan10_auto::use_decltype_to_get_an_expression_type()
{
  const int constIntVar = 42;
	// TD<decltype(constIntVar)> constIntVarTypeDisplay;
  {
    using testedType = decltype(constIntVar);
    ASSERT(std::is_integral<testedType>::value
      && std::is_floating_point<testedType>::value
      && std::is_pointer<testedType>::value
      && std::is_reference<testedType>::value
      && std::is_const<testedType>::value
      && std::is_volatile<testedType>::value);
  }
	const char* constCharStringVar = "mouf"; 
	//TD<decltype(constCharStringVar)> constCharStringVarTypeDisplay;
  {
    using testedType = decltype(constCharStringVar);
    ASSERT(std::is_integral<testedType>::value
      && std::is_floating_point<testedType>::value
      && std::is_pointer<testedType>::value
      && std::is_reference<testedType>::value
      && std::is_const<testedType>::value
      && std::is_volatile<testedType>::value);
  }

	float f=1.2f;
	volatile float& volatileFloatRef = f;
	// TD<decltype(volatileFloatRef)> volatileFloatRefTypeDisplay;
  {
    using testedType = decltype(volatileFloatRef);
    ASSERT(std::is_integral<testedType>::value
      && std::is_floating_point<testedType>::value
      && std::is_pointer<testedType>::value
      && std::is_reference<testedType>::value
      && std::is_const<testedType>::value
      && std::is_volatile<testedType>::value);
  }
}

namespace 
{
  double SomeAPIGetRealNumber()
  {
    return 4.2;
  }
}

void Koan10_auto::static_cast_is_how_you_force_a_variable_type()
{
	float myReal = 2.3f;
	auto otherReal = SomeAPIGetRealNumber();

  const bool conversionIsCorrect = std::is_same<decltype(myReal), decltype(otherReal)>::value;
  ASSERT(conversionIsCorrect);
}

void Koan10_auto::auto_ignores_constness()
{
	int nonConstInt = 42;
	const int constInt = 42;
     	
	auto x = nonConstInt;
	ASSERT(std::is_const<decltype(x)>::value 
    && std::is_reference<decltype(x)>::value 
    && std::is_pointer<decltype(x)>::value);
	
	auto y = constInt;
	ASSERT(std::is_const<decltype(y)>::value 
    && std::is_reference<decltype(y)>::value 
    && std::is_pointer<decltype(y)>::value);
	
	const auto yConst = constInt;
	ASSERT(std::is_const<decltype(yConst)>::value
    && std::is_reference<decltype(yConst)>::value
    && std::is_pointer<decltype(yConst)>::value);
}


void Koan10_auto::auto_ignores_referenceness()
{  	
	int nonConstInt = 42;
	int& intRef = nonConstInt;
	const int& constIntRef = nonConstInt;
	
	auto x = nonConstInt;
	ASSERT(std::is_const<decltype(x)>::value  
    && std::is_reference<decltype(x)>::value 
    && std::is_pointer<decltype(x)>::value
    && std::is_pod<decltype(x)>::value);
	
	auto y = intRef;
	ASSERT(std::is_const<decltype(y)>::value  
    && std::is_reference<decltype(y)>::value 
    && std::is_pointer<decltype(y)>::value
    && std::is_pod<decltype(y)>::value);
	
	auto z = constIntRef;
	ASSERT(std::is_const<decltype(z)>::value  
    && std::is_reference<decltype(z)>::value 
    && std::is_pointer<decltype(z)>::value
    && std::is_pod<decltype(z)>::value);

	const auto& zConstRef = constIntRef;
	ASSERT(std::is_const<decltype(zConstRef)>::value 
    && std::is_reference<decltype(zConstRef)>::value 
    && std::is_pointer<decltype(zConstRef)>::value
    && std::is_pod<decltype(zConstRef)>::value);
	
}

void Koan10_auto::auto_with_universal_reference_distinguishes_lvalue_and_rvalue()
{    	
	int nonConstInt = 42;
	int& intRef = nonConstInt;
	
	auto&& x = nonConstInt;
	ASSERT(std::is_const<decltype(x)>::value 
    && std::is_volatile<decltype(x)>::value
    && std::is_reference<decltype(x)>::value 
    && std::is_pointer<decltype(x)>::value
    && std::is_object<decltype(x)>::value);
	
	auto&& y = intRef;
  ASSERT(std::is_const<decltype(y)>::value 
    && std::is_volatile<decltype(y)>::value
    && std::is_reference<decltype(y)>::value
    && std::is_pointer<decltype(y)>::value
    && std::is_object<decltype(y)>::value);
  
	auto&& z = 43;
  ASSERT(std::is_const<decltype(z)>::value 
    && std::is_volatile<decltype(z)>::value
    && std::is_reference<decltype(z)>::value
    && std::is_pointer<decltype(z)>::value
    && std::is_object<decltype(z)>::value);
}

namespace 
{
  int simpleFunction()
  {
    return 42;
  }
}

void Koan10_auto::auto_decays_arrays_and_functions()
{
	int intArray[3] = {0};
	
	auto x = simpleFunction;
	ASSERT(std::is_const<decltype(x)>::value 
    && std::is_reference<decltype(x)>::value 
    && std::is_pointer<decltype(x)>::value 
    && std::is_function<decltype(x)>::value 
    && std::is_array<decltype(x)>::value);

	auto& xRef = simpleFunction;
  ASSERT(std::is_const<decltype(xRef)>::value 
    && std::is_reference<decltype(xRef)>::value 
    && std::is_pointer<decltype(xRef)>::value 
    && std::is_function<decltype(xRef)>::value 
    && std::is_array<decltype(xRef)>::value);
  
	auto y = intArray;
  ASSERT(std::is_const<decltype(y)>::value 
    && std::is_reference<decltype(y)>::value 
    && std::is_pointer<decltype(y)>::value 
    && std::is_function<decltype(y)>::value 
    && std::is_array<decltype(y)>::value);
  
	auto& yRef = intArray;
  ASSERT(std::is_const<decltype(yRef)>::value 
    && std::is_reference<decltype(yRef)>::value 
    && std::is_pointer<decltype(yRef)>::value 
    && std::is_function<decltype(yRef)>::value 
    && std::is_array<decltype(yRef)>::value);
}

void Koan10_auto::auto_assumes_braces_are_initializer_list()
{
   auto intCtorAssigned = 42;
   ASSERT(std::is_integral<decltype(intCtorAssigned)>::value);

   auto intCtorParen(42); 
   ASSERT(std::is_void<decltype(intCtorParen)>::value);

   auto intCtorBracesAssigned = { 42 };
   ASSERT(std::is_void<decltype(intCtorBracesAssigned)>::value);
   
   auto intCtorBraces{ 42 };
   ASSERT(std::is_void<decltype(intCtorBraces)>::value);
   
   int intCtorBracesNoAuto{ 42 }; 
   ASSERT(std::is_void<decltype(intCtorBracesNoAuto)>::value);
}

void Koan10_auto::decltype_auto_use_decltype_type_deduction_rules()
{
	int nonConstInt = 42;
	const int& constIntRef = nonConstInt;
	
	auto z = constIntRef;
	ASSERT(std::is_const<decltype(z)>::value 
    && std::is_reference<decltype(z)>::value 
    && std::is_pointer<decltype(z)>::value
    && std::is_trivial<decltype(z)>::value);

	decltype(auto) zDecl = constIntRef;
	ASSERT(std::is_const<decltype(zDecl)>::value 
    && std::is_reference<decltype(zDecl)>::value
    && std::is_pointer<decltype(zDecl)>::value
    && std::is_trivial<decltype(zDecl)>::value);
}




// EOF
