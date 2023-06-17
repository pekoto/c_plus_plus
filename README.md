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

## Statements & Operators

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

## strings

Use `#include <cctype>` to get various helper functions.

Eg

`toupper(c) isalpha(c)

### c-style strings
`#include <cstring>`
`#include <cctype>` char functions

An array of chars terminated with the null character.

* string literal: sequence of chars enclosed in double quotes. Non-mutable.

```cpp
char str[80];
strcopy(str, "hello");
strcat(str, "there");
```


```cpp
cin.getline(name, 50) // read in up to 50 chars
```

### C++ strings

```cpp
#include <string>
```

* used more commonly than c strings
* Dynamic size
* Safer
* Can be converted to C strings if required

```cpp
string s1 {"Frank"};
```

```cpp
// concatenation
string sentence;

string s1 {"hello"};

sentence = s1 + " " + "world";

sentence += "!";

// the following wont work as it is trying to concatenation 2 c style strings
sentence = "hello" + " world";

// iterate chars
for (char c: sentence)
    cout << c << endl;
    
// get length
cout << sentence.length() << endl;


```

Comparison:
Can use standard operators:

`==, !=, <, >`


## Functions
To find predefined functions, see c++ standard library header files at cop reference.com.

```cpp
// basic function
int add_numbers(int a, int b) {
    return a + b;
}

void print_hi() {
    cout << "hi!" << endl;
}

void print_arr(int nums []);

```

### Common libs
* cmath
* cstdlib

### Function Prototypes
Functions must be defined _before_ they are called.

This can become problematic with large programs, so we use __function prototypes__.

Function prototypes tell the compiler what it needs without a function definition.

Also sometimes called forward declarations.

These can be stored in `.h` files.

```cpp
// note: the name a can also be omitted 
int my_function(int a); // prototype

int my_function(int a) { // function
   return a;
}

// default value
double calc_cost(double base_cost, double tax_rate = 0.06); // prototype
```

### function parameters

In C++, parameters are passed by value (ie a copy of the data is passed in). Note this is true even for objects. It's not like Java where we pass a copy of the reference. Except arrays, which will have elements changed.

Formal parameters: the parameters defined in function header
Actual parameters: the parameters passed in as arguments

### Function overloading

A type of polymorphism: same function name with different parameters. The compiler works out which version of the function to use.

```cpp
int add_numbers(int, int);

double add_numbers(double, double)
```

Note: return type is not considered. So parameter types must differ.

### Array parameters

Array elements can be changed in function bodies because all that's passed in is reference to the first element in memory. Also because of this, you need to pass in the size.

To avoid changing the array by mistake, you can also use `const` in the parameter, to tell the compiler it's read only.

```cpp
void print_arr(const int nums[], size_t size) {
   ...
   nums[0] = 10; // compiler error since const
}

```

### Pass by reference

Use pass by reference to modify the actual parameter passed in.

This can be done by using a reference with `&`.

```cpp
void set_to_zero(int &num){
   num = 0;
}
 ```

* pass by reference: `&`

If we just want to improve performance by avoiding copying but don't want to accidentally change values we can use `const`
again.

```cpp
void print_vec(const vector<int> &v);

```

### Inline functions

Function calls have some overhead and they are pushed and popped from the stack.

Sometimes we have simple functions.

We can suggestion the compiler compiles them __inline__.

Online functions avoid function call overhead, generate inline assembly code, faster, but can cause code bloat (end up with large binaries as you repeat the code).

Compilers can also inline even without your suggestion.

```cpp
inline int add_numbers(int a, int b);

```

## Pointers

Pointers are variables that store the address of another variable or function.

If you don't initialize a pointer, it will contain garbage data.

__Derefencing__ a pointer: accessing the data the pointer is pointing to.
To do this, use the dereference operator `*`.
In other words, we go to whatever the pointer is pointing at.

```cpp

int score {100};
int *score_ptr {&score}; // Initialize pointer and point it to the memory address of score.

cout << *score_ptr << endl; // Prints 100

*score_ptr = 200;

cout << *score_ptr << endl;  // Prints 200
cout << score << endl; // Prints 200

```

### Note on frequent confusion

Although the `*` symbol is used to initialize a pointer AND dereference a pointer,
they are __not__ the same.

Pointer assignment without the dereference operator must point to an address.

Pointer assignment with the dereference operator must point to a variable or number etc.

```cpp

int a {100};
int b {200};
int *p {&a}; // When we initialize, we must use an address

cout << *p << endl; // 100 (dereferencing)
*p = 150; // 150 (set contents of p to 150, contents must be an int).
cout << *p << endl; // 150

p = b; // COMPILER ERROR: P itself must be set to an address

p = &b; // Setting p must be set to an ADDRESS

cout << *p << endl; // 200

```

### Dynamic Memory Allocation

```cpp

// Allocate space for an int
int *int_ptr {nullptr};
int_ptr = new int;  // Allocate space for an integer on the heap
*int_ptr = 100;  // Set it to 100
cout << *int_ptr << endl; // 100
delete int_ptr;  // Frees allocated memory

// Allocate space for an array
size_t size{0};
double *temp_ptr{nullptr};

cout << "How many temps?";
cin >> size;
temp_ptr = new double[size];  // Allocate space contiguously in memory for this array.
delete [] temp_ptr;  // Release the memory

```

```cpp

int scores[] {100, 95, 89, -1};
int *score_ptr {scores};

// Array subscript location
cout << scores[0] << endl;  // 100

// Pointer subscript notation
cout << score_ptr[0] << endl; // 100 (remember, array is just a memory location that points to the start of an array)

// Pointer offset notation
cout << *score_ptr << endl; //100
cout << *(score_ptr+1) << endl; // 95 (move the address by 1 int and get what is there)

// Array offset notation
cout << *scores << endl; // 100
cout << *(scores + 1) << endl;  // 95  (get the next address and dereference to it)

while (*score_ptr != -1) {
    cout << *score_ptr << endl;
    score_ptr++;
    // May also see cout << *score_ptr++ << endl;
}

```

### Pointer Arithmetic

Pointer arithmetic is useful for manipulating arrays.

* `int_ptr++;`: increments a pointer to point to the next element in an array
* `int_ptr--;`: decrements a pointer to point to the previous element in an array
* `int_ptr1 == int_ptr2`: Will compare if they are both pointing to same address
* `*int_ptr1 == *int_ptr2`: Will compare the things that are at the addresses via dereferencing

### const and pointers

We can have


* pointers to constants: data pointed to can't change but constant can't point elsewhere ```cpp const int *score_ptr { &high_score}; *score_ptr=86; // error score_ptr = &low_score; // okay```
* Constant pointers: the data pointed to can be changed but the constant itself cannot be

```cpp
int *const score_ptr { &high_score}; *score_ptr=86; // okay 
score_ptr = &low_score; // error


```


* Constant pointers to constants: pointer can't change and neither can the data pointed to


```cpp
const int *const score_ptr { &high_score}; *score_ptr=86; // error 
score_ptr = &low_score; // error


```

### Pointers to functions (pointers as args)

You can pass in a pointer to an argument to pass by reference.

```cpp

void double_data(int *int_ptr);

void double_data(int *int_ptr) {
   *int_ptr *= 2;
}

void display(vector<string> *v) {
    for (auto str: *v) {
        cout << str << endl;
    }
}

int main() {
    int val{100};
    double_data(&val); // NB: When param is pointer, pass in address

    cout << val << endl; // 200
    
    // for iterables we have to dereference the pointer passed in to get to the object
    vector<string> v {"a", "b", "c"};
    display(&v);
}
```

### Pointers from functions (pointers as return types)

A common use case for returning a pointer from a function is to use the function to allocate memory
dynamically, and then return the address of that memory.

We can use `*` after the return arg type to say it's returning a pointer.

```cpp

#include <iostream>
#include <vector>
using namespace std;

int *create_array(size_t size, int init_value = 0) {
    int *new_storage{nullptr};

    new_storage = new int[size];  // Allocate size integers on the heap (not stack)

    for (size_t i{0}; i < size; ++i) {
        *(new_storage +i) = init_value;
    }

    return new_storage;
}

void display(const int *const array, size_t size) {
    for (size_t i{0}; i < size; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main() {
    int *my_array{nullptr};

    my_array = create_array(3, 0);

    display(my_array, 3);

    delete [] my_array;

    return 0;
}
```

### Pointer Pitfalls

Note new "smart pointers" can take care of many of these issues.

#### Uninitialized Pointers

Pointers that point to random data because they weren't initialized.

```cpp

int *int_ptr;  // Pointing somewhere random, maybe containing important data.

*int_ptr = 100;  // Hopefully makes program crash, but could cause weird bugs.

```

#### Dangling Pointers

Pointer pointing to released memory.
E.g., 2 pointers point to the same data, 1 pointer releases the data with delete,
the other pointer is pointing to released memory.
Or points to some local variable.

#### Not checking if new failed

If `new` fails an exception is thrown.

#### Memory leak

You allocate memory on the heap dynamically, but it has no pointer pointing to it.
This is a memory leak.

### References

* An alias for a variable
* Once initialized, cannot be made to refer to a different variable
* Useful as function parameters
```cpp

    int num{100};
    int &ref{num};
    
    cout << num << endl; // 100
    cout << ref << endl; // 100
    
    num = 200;
    
    cout << num << endl; // 200
    cout << ref << endl; // 200
    
    ref = 300;
    
    cout << num << endl; // 300
    cout << ref << endl; // 300

```

### l-values and r-values

Recall that an l-value is something on the LHS, and everything is an r-value.
References are l-values, so when we try to assign or pass a ref, we must use an l-value.

```cpp

int square(int &n) {
    return n*n;
}

int num {10};

square(num); // OK

square(5); // Error -- can't reference r-value

// Another example

int x {100};

int &ref1 = x;  // OK (x is an l-value)
ref1 = 1000; // OK

int &ref2 = 100;  // Error -- 100 is an r-value.

```

### Pointers vs. References

* Pass-by-value
  * Default behavior
  * Function does not modify actual parameters
  * Parameter is small and efficient to copy (ints, etc)
* Pass-by-reference using pointer
  * Function modifies the actual parameter
  * AND parameter is expensive to copy
  * AND OK for pointer to be allowed a `nullptr` value
  * Can use const if we just want to save on expensive copying but not modify pointer/values
* Pass-by-reference using reference
  * Function modifies the actual parameter
  * AND parameter is expensive to copy
  * AND the pointer will never be `nullptr`
* 