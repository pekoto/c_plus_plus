# C++ Notes

## Versions

* Classical C++: Pre-C++ 11 standard
* "Modern" C++: C++ 11 onwards (currently C++ 20, but although that standard has been published,
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

* [cpp.sh](https://www.cpp.sh)

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

## Program Structure

* Identifiers: things that the programmer names. E.g. `endl`, include, etc.

### include preprocessor

The C++ preprocessor is a program that processes the source code before the compiler sees it.

1. Strips out comments and replaces with spaces
2. Executes preprocessor directives (statements starting with a `#`)

Example preprocessor directives:

```cpp


#include <iostream>
#include "myfile.h"

#if
#elif
#else
#endif

#ifdef
#ifndef
#define
#undef

#line
#error
#pragma


```

For include, it recursively processes the files after the `#include`.

Preprocessors can be used to conditionally compile your source code. For example, use preprocessor directives to work out if you are on windows or not, and if you are include some windows libraries.

### Comments

```cpp

// Single line comment.

/*

 Multi-line comment comment.

*/

```

### main()

* Every C++ program must have exactly 1 `main()` function
* `main()` if the point of program execution
* 0 indicates successful execution
* Can have args or not

```cpp

int main()
{
	return 0;
}

// argc: number of arguments passed in
// argv: vector of arguments passed in
int main(int argc, char *argv[])
{
	return 0;
}

```

### Namespaces

* Naming container given to libraries to reduce naming conflicts
* `std`: "Standard" C++ namespace
* `::` scope resolution operator
* If you don't want to type, e.g., `std::` every time you can use `using namespace` instead:

```cpp


using namespace std;

int main() {

	count << "Hello, world.";

	return 0;
}

```

You can also specify specific namespaces:

```cpp

using std::cout;

int main() {

	cout << "Hello, world.";

	return 0;

}

```

### Basic I/O

The following represent streams:

* `cout`: standard output, to console
* `cin`: standard input, keyboard
* `<<`: insertion operator (output)
* `>>`: extraction operator (input)

`cout` and `<<` __inserts__ the data to the thing on the left.

```cpp
cout << "data 1 is " << data1 << endl;
```

`cin` and `>>` __extracts__ data __from__ the input stream to the data.

```cpp
cin >> data1 >> data2;
```

## Variables & Constants

### Initialization

```cpp

int age;  // Uninitialized

int age = 21;  // C-like initialization

int age (21);  // Constructor initialization

int age {21};  // C++11 list initialization syntax (recommended)

```

### Primitive Types

##### Character data types

* `char`: 8 bits, 1 byte, can represent 256 chars
* `char16_t`: At least 16 bits, 2 bytes
* `char32_t`: At least 32 bits, 4 bytes
* `wchar_t`: Can represent largest available character set


#### Numerical data types

By default, integers are signed.

* `signed short int`: At least 16 bits
* `signed int`: At least 16 bits
* `signed long int`: At least 32 bits
* `signed long long int`: At least 64 bits


* `unsigned short int`: At least 16 bits
* `unsigned int`: At least 16 bits
* `unsigned long int`: At least 32 bits
* `unsigned long long int`: At least 64 bits

* `float`: 7 decimal digits
* `double`: 15 decimal digits
* `long double`: 19 decimal digits

#### Boolean

* `bool`: Can also use 0 and 1

### sizeof

Use `sizeof(var)` to get the size of variables.

The information comes from `#include <climits>`.

`climits` also contains useful constants such as `INT_MIN`.

Number may look different on different machines and different compilers.

### Constants

`const double pi {3.1415926};`

`#define pi 3.1415926`  (legacy, not used in modern C++)

## Arrays & Vectors

Note: Arrays are rarely used over vectors in modern C++, but still appear in legacy C++
occasionally.

```cpp

// type array_name [size] {init list};

// Declare 5 elements with value 0
int test_scores [5];

// Initialize first 2 elements to 3 and 5, and the rest to 0.
int high_scores [10] {3, 5};

// Init all to zero
double hi_temps [365] {0};

// Size automatically
int some_array [] {1, 2, 3, 4, 5};

// Set element
some_array[0] = 90;

// Access element
cout << some_array[0] << endl;

// Multidimensional array, 3 rows x 4 columns
int movie_ratings [3][4];

movie_ratings [0][0] = 99;
```

### Vectors

```cpp

#include <vector>
using namespace std;

// Initialize to size 5 using constructor syntax.
vector <char> vowels (5);

// Initialize with elements.
vector <char> vowels {'a', 'e', 'i', 'o', 'u'};

// Initialize with size, and default value.
vector <double> hi_temps (365, 80.0);

// Access elements using subscripting or at
cout << "First element is " << hi_temps[0] << endl;
cout << "First element using at is " << hi_temps.at(0) << endl;

// Assign elements can also use at
hi_temps.at(0) = 100.0;

// Use push_back to add to the end of the vector and allocate required space.
// IMPORTANT: Push back will make a copy of the object.
hi_temps.push_back(500.0);

// Get the size
cout << hi_temps.size() << endl;

// 2D vectors
vector<vector<int>> movie_ratings {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9},
};

// Access
cout << movie_ratings[0][1] << endl;
cout << movie_ratings.at(0).at(1) << endl;


```

## Statements & Operators (Anki from here)

### Lvalues and Rvalues

* `lvalue` = LHS of expression, object reference
* `rvalue` = RHS of expression, the value

### Prefix / Postfix increment

```cpp
int i = 10;
int j = 0;

j = i++; // j is 10, i is 11 (post-increment, assign to j and then increment it)

j = ++i; // j is 12, i is 12 (pre-increment, increment i and then assign it)


```
### Mixed Type Expressions

```cpp

int total_acount {100};
int total_number {8};
double average {0.0};

// Divide when both are integers
cout << total_amount / total_number << endl; // 12

// Cast total_amount to double
cout << static_cast<double>(total_amount) / total_number << endl; // 12.5

```

Use `static_cast` to do conversion.
Static cast makes sure it can be converted to that type.

### Logical Operators

* `!`: not
* `&&`: and
* `||`: or

You can also use `not`, `and`, `or`, but not commonly used.

## Control Structures

### Conditional operator

`result = (a > b) ? a : b;`

### Loops

```cpp

vector<int> scores {100, 90, 82};

// For loop
// We use (size_t) unsigned since size() is unsigned, and otherwise
// we will get warnings about comparing signed and unsigned.
// size_t is an unsigned into that is guaranteed to be big enough
// to hold the biggest object your system can handle.
for (size_t i {0}; i < scores.size(); ++i) {
    cout << scores[i] << endl;
}

// Range-based for loop
for (auto score: scores) {
    cout << score << endl;
}

for (auto c: "Frank") {
    cout << c << endl;  // Prints out a char at a time.
}



```

