# C++ Notes

## Versions

* Classical C++: Pre-C++ 11 standard
* "Modern" C++: C++ 11 onwards (currently C++ 20, but althoughthat standard has been published,
most implementations are still C++ 17).

## Reminder

* Source code > compiler > object code (machine code) > linker > executable
* Object files: Windows: .obj, Mac/linux: .o
* Linker: links our code with other libraries
* Creates the executable program

## Compilation

`g++ -Wall -std=c++14 main.cpp -o main`

* `g++`: Compiler
* `-Wall`: All Warnings
* `-std=c++14` The C++ standard to use
* `main.cpp` The file to compile (add more by just adding, separated by spaces)
* `-o main` The object file to generate

To run: `./main`

### Linker Errors

Occur when the linker is having trouble linking all the object files together to create an executable.

Usually a library or object file is missing. Could also be a path problem.

## Web Compilers

* [cpp.sh](cpp.sh)
* [webcompiler.cloudapp.net](webcompiler.cloudapp.net)

## Basics

```cpp
#include <iostream>

// All C++ programs must have exactly 1 main function.
int main() {

    int favourite_number;

    // Output to the console.
    // << == insertion operator, used for output.
    std::cout << "Enter your favourite number between 1 and 100.";

    // Read the input from standard in.
    // >> == extraction operator, used for input.
    std::cin >> favourite_number;

    // Print out and flush the buffer, put cursor on new line.
    std::cout << "Amazing! That's my favourite number too!" << std::endl;

    return 0;
}
```
