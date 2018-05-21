# CppKoans

Inspired by [RubyKoans](https://github.com/edgecase/ruby_koans) and 
[JavaScript-Koans](https://github.com/liammclennan/JavaScript-Koans), this is
an attempt to write such koans for C/C++.

Some ideas were taken from [PointerKoans](https://github.com/paytonrules/PointerKoan).

### Prerequesites
You will need [CMake](http://cmake.org/).

And of course a C++ compiler.
I just tested it with a recent GCC.

## How to walk the path to enlightment
1. Get the sources

        git clone git://github.com/torbjoernk/CppKoans.git

2. Create a build directory

        cd CppKoans
        mkdir build
        cd build

3. Configure the build

        cmake ./..

4. Compile

        make

5. Run

        ./CppKoans


Now follow the instructions printed from the very beginning.

The files, you will need to edit are in `CppKoans/koans`.
Each time you saved a file and want to rerun the koans, you need to compile it
first.
Thus, walking the path to enlightment is a repetition of these steps:

1. Edit and save a file in `CppKoans/koans`

2. Compile in `CppKoans/build` by running `make`

3. Read the master's reply with `./CppKoans/build/CppKoans`


## Adding further Koans
### To existing episodes
Just define a new `private void` function without parameters in the bottom
section of the episode's header file it should belong to.
Then go to the implementation file of that episode and implement your new koan.
Finally add your newly created koan to the `run()` function in the header file
of that episode and increase the `num_tests` counter by one (or whatevery amount
of koans you added).

### New episodes
There is a sample episode, which can be used as a template for new episodes.
After copying and renaming of `~/headers/koanXX_sample_koans.hpp` and
`~/koans/koanXX_sample_koans.cpp` the following steps are necessary:

1. add the implementation file to `~/koans/CMakeLists.txt`

2. add the header file to `~/headers/all_koans.hpp`

3. enable and activate the new episode in `~/cppkoans.cpp`


## Licence
MIT License Copyright 2012 Torbjörn Klatt - opensource eht torbjoern minus klatt dot de