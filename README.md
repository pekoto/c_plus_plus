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

## Object-oriented Programming

### Declaring a class

Declare the class in a header file.
It uses an __include guard__ to ensure it's only processed once.

```cpp
// Account.h

#ifndef _ACCOUNT_H_ // include guard, if not defined...
#define _ACCOUNT_H_ // include guard
// Some compilers support #pragma once which does the same thing.
#include <string>

using namespace std;

class Account {

    // Attributes
private:
    string name;
    double balance;

public:
    // Constructors
    Account();
    Account(string name);
    Account(string name, double balance);
    Account(double balance);

    // Alternatively just have one constructor with default args
    Account(string name_val = "None", double balance = 0.0)

    // Destructors (have a ~)
    // invoked automatically when object is destroyed, only 1 can exist, free up resources, etc.
    ~Account();

    // Methods
    void set_name(string n);
    string get_name();
    
    void set_balance(double bal);
    double get_balance();

    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // include guard
```

Then define the class:

```cpp
// Account.cpp (prefix class name and scope resolution operator ::)
#include "Account.h"  // Using include with <> means system header files, but using double quotes means this class is local to this project.
#include <string>

using namespace std;


// Constructors
Account::Account(string name_val, double balance_val) : name{name_val}, balance{balance_val} {
    // Use constructor initialization list

};

Account::Account() : Account{"None", 0.0} {
    // Constructor delegation to other constructor
}

Account::Account(string name_val) : Account{name_val, 0.0} {

}


Account::Account(double balance_val) : Account{"None", balance_val} {

};

// Destructors (have a ~)
// invoked automatically when object is destroyed, only 1 can exist, free up resources, etc.
Account::~Account() {
    std::cout << "Account destroyed" << std::endl;
}

void Account::set_name(string name) {
    this->name = name;
}

string Account::get_name() {
    return name;
}

void Account::set_balance(double balance) {
    this->balance = balance; // Use -> with this
}

double Account::get_balance() {
    return balance;
}

bool Account::deposit(double amount) {
    balance += amount;
    return true
}

bool Account::withdraw(double amount) {
    if (balance-amount >= 0) {
        balance -= amount;
        return true;
    } else {
        return false;
    }

}

```

Then use the class by including the header file again.

```cpp

#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

using namespace std;

int main() {
    Account frank_account;
    Account hero_account;

    Player frank;
    Player hero;

    // Create enemy on the heap
    Player *enemy{nullptr};
    enemy = new Player;

    // To access pointers to an object...
    // 1. Dereference the pointer
    (*enemy).name = "Person");
    // 2. OR use the member of pointer operator (arrow operator)
    enemy->name = "Person";

    delete enemy;
    
    Account my_account;
    my_account.set_name("Graham");
    cout << my_account.get_name() << endl;

    return 0;
}

```


### Constructor Initialization Lists

Constructor initialization lists initialize default attributes as the object is created.

```cpp

Player::Player(): name{"None"}, health{0}, xp{0} {

}

Player::Player(string name_value): name{name_value}, health{0}, xp{0} {

}

```

### Delegating Constructors

A way to reduce duplication in constructors.

```cpp

Player::Player(string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {

}

Player::Player() : Player {"None", 0, 0} {

}

Player::Player(string name_val) : Player {name_val, 0, 0) {

}

```

### Copy Constructors

C++ will provide a compiler provided copy constructor if you don't provide one.
Ie. it copies the values of each member to the new object. This is okay unless you have attributes that are pointers. In this case only the pointer is copied ("shallow copy").

* Used when...
    * Passing an object by value
    * Returning an object by value
    * Constructing one object based on another 

Copy constructors look like constructors, but take in a single object as a constant reference of the same type. `const` because we don't want to change the source, and a reference because we don't want to make a copy of it -- that's the whole point!

```cpp
// Prototype
Account(const Account &source);

// Implementation
Account::Account(const Account &source) : name{source.name}, balance{source.balance} {

}

```

#### Shallow Copying & Deep Copying

With the default copy constructor, each member is copied from the source object.
For pointers, the __pointer__ is copied, but not what it's pointing to.
When we release the storage, the other object still refers to the storage that was released by our copy!

##### Shallow Copy Example

```cpp

class Shallow {

private:
    int *data; // Pointer

public:
    Shallow(int d); // Constuctor
    Shallow(const Shallow &source); // Copy Constructor
    ~Shallow(); // Destructor
}

// Constructor
Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

// Copy constuctor
// PROBLEM: Source and the new object both point to the same data!
Shallow::Shallow(const Shallow &source) : data(source.data) {
     cout << "Created copy" << endl;
}

// Destructor
Shallow::~Shallow() {
    // PROBLEM: The original object will still point to the released member when the copy is destroyed.
    delete data; // Free storage
    cout << "Freed storage" << endl;
}

```

##### Deep Copy Example

With a deep copy, we copy the data pointed to by the pointer. When we have raw pointers, we always want to implement a deep copy constructor.

```cpp

class Deep {

private:
    int *data;

public:
    Deep(int d);
    Deep(const Deep &source);
    ~Deep();
}

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

// Copy constuctor
Deep::Deep(const Deep &source) {
     data = new int; // Allocate storage for a copy
     *data = *source.data; // Copy the value of what we are pointing to into this storage
     cout << "Created copy" << endl;
}

// We could also do constructor delegation
Deep::Deep(const Deep &source) : Deep{*source.data} {
    // Copy constructor using delegation.
}

// Destructor
Deep::~Deep() {
    // PROBLEM: The original object will still point to the released member when the copy is destroyed.
    delete data; // Free storage
    cout << "Freed storage" << endl;
}
```

### Move Constructors

When we execute code, the compiler creates temporary values.

```cpp

int total{0};
total = 100 + 200;

```

* When `100+200` is evaluated, `300` is stored in an un-named temp value.
* Then 300 is stored in the variable total
* Then the temp value is discarded
* The same thing happens with objects

Move constructors are useful when:

* Copy constructors are called many times, doing deep copying
* Move constructors simply move the object rather than copy it
* Optional but recommended when you have a raw pointer

##### R-value References

* Used in moving semantics and perfect forwarding
* Move semantics all about r-value references
* Used by the move constructor and move assignment operator to move an object instead of copying it
* R-value reference operator: `&&`

```cpp

int x{100};
int &l_ref = x; // l-value reference
l_ref = 10; // change x to 10

int &&r_ref = 200; // r-value reference
r_ref = 300; // change r_ref to 300

int &&x_ref = x; // compiler error (trying to assign r-value ref to l-value)

```

Consider functions:

```cpp

int x{100};

void func1(int &num);

func1(x); // Okay -- x is an l-value
func1(200); // Error -- 200 is an r-value

void func2(int &&num);

func2(200); // Okay -- 200 is an r-value
func2(x); // Error - x is an l-value

// NOTE: We can define both
void func(int &num);
void fund(int &&num);

```

Let's look at the move constructor:

```cpp

class Move {

private:
    int *data;

public:
    void set_data(int d) { *data = d; }
    int get_data() { return *data; }
    Move(int d);  // Constructor
    Move(const Move &source;) // Copy Constructor
    Move(Move &&source) // Move Constructor
    ~Move(); // Detructor
}

// Copy constructor
Move::Move(const Move &source) {
    data = new int;
    *data = *source.data;
}

// Move constructor
// Think of it like, stealing the data and then nulling out the original
Move::Move(Move &&source) : data{source.data} {
    source.data = nullptr;  // Null out the original pointer
}

```

Now if we run the following, the copy constructor will be called to copy the temp `10` and `20`.

```cpp

Vector<Move> vec;

// Move constructors will be called for the temp values.
vec.push_back(Move{10});
vec.push_back(Move{20});

```

### Const with Classes

Creating a `const` object means none of its attributes can be changed.

```cpp

const Player villain {"Villain", 100, 5};

villain.set_name("New name"); // Compiler error

villain.get_name(); // PROBLEM: This will also throw an error since this function could change it!

```

The solution is that we need to tell the compiler specific methods will not modify the object. We do this by adding `const` before the semi-colon in the method prototype.

```cpp

class Player {

public:
    string get_name() const; // This is okay

}


```

### Static Class Members

* A single member that belongs to the class rather than a single instance of that class.

##### Player.h

```cpp

class Player {

private:
    static int num_players;

public:
    static int get_num_players();

}

```

##### Player.cpp

```cpp

#include "Player.h"

int Player::num_players = 0;

int Player::get_num_players() {
    return num_players;
}

```

##### main.cpp

```cpp

cout << Player::get_num_players() << endl;

```

### Structs vs Classes

* `struct` comes from C and is another way to make an object
* Essentially the same as a class, except members are `public` by default

```cpp

struct Person {
    string name;
}

Person p;
p.name = "Frank";

```

* struct
    * Use for passive objects with public access
    * Don't declare methods
* class
    * Active objects with private access
    * Implement getters/setters as needed
    * Implement member methods as needed

### Friends of a Class

* Friend
    * Function or class that has access to private class member
    * AND that function is NOT a member of the class it is accessing
* Function
    * Can be regular non-member function
    * Can be member methods of another class
* Class
    * Another class can have access to private class members

```cpp

class Player {

    // Display player has access to everything in the Player class
    friend void display_player(Player &p);
    friend class Other_class;

};

void display_player(Player &p) {
    // Can access private members
}

```

Might use `friend` when getters / setters become long and complicated, but generally be wary of using it.``

## Operator Overloading

* Lets you use traditional operators like `+, *` etc. with user-defined types

### Overloading Copy Assignment (=)

* Don't confuse initialization with assignment
* Initialization happens when the object is being created for the first time (it hasn't been created yet)
* Assignment happens once the object has been initialized.
* If you don't provide an assignment operator, it will do memberwise assignment (shallow copy).

```cpp

Mystring s1{"Frank"};
Mystring s2 = s1; // NOT assignment
s2 = s1; // assignment

```

To overload an operator, we use `Type &Type::operator=(const Type &rhs);`

```cpp

// Prototype
Mystring &operator=(const Mystring &rhs);

// Implementation
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs)  // Check for self-assignment
        return *this;

    delete [] str;  // Free storage that the old pointer was pointing to
    str = new char[std::strlen(rhs.str + 1)];
    std::strcpy(str, rhs.str);

    return *this;
}

```

### Overloading Operators as Member Functions

We don't return a reference but a value type, because we are returning a new type.

Overloading unary operators:

```cpp
// General signature
Returntype Type::operatorOp();

Number Number::operator-() const;
Number Number::operator++();    // pre-increment
Number Number::opeartor++(int); // post-increment
bool Number::operator!() const;

```

Example showing overloading the `-` unary operator to make a string lowercase:

```cpp

Mystring Mystring::operator-() const {  // const because we don't want to modify current object, but create a new object based on it.
    char *buff = new char[std::strlen(str)+1]; // allocate space to store copy
    std::strcopy(buff, str); // copy string over
    for (size_t i=0; i<std::strlen(buff); i++) {  // make each char lowercase
        buff[i] = std::tolower(buff[i]);
    }

    Mystring temp{buff}; // Construct new object using temp string as initializer
    delete buff; // Delete temp string
    return temp; // Return new object
}

```

Overloading binary operators (operators that take two parameters):

```cpp

ReturnType Type::operatorOp(const Type &rhs);

Number Number::operator+(const Number &rhs) const;
Number Number::operator-(const Number &rhs) const;
bool Number::operator==(const Number &rhs) const;
bool Number::operator<(const Number &rhs) const;

Number n1{100}, n2{200};
Number n3 = n1 + n2; // n1.opeartor+(n2);

```

Overloading `==`

```cpp

bool Mystring::operator==(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) == 0) {
        return true;
    } else {
        return false;
    }
}

if (s1 == s2)...

```

Overload `+`:

```cpp

Mystring Mystring::operator+(const Mystring &rhs) const {

    size_t buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;
    char *buff = new char[buff_size];
    std::strcpy(buff, str);
    std::strcat(buff rhs.str);
    Mystring temp {buff}
    delete [] buff;
    return temp;
}

```

### Operator Overloading with Global Functions

Instead of overriding functions as class member functions, we can also override them as global functions. When doing this, we often mark them as __friend__ so we can access private attributes.

```cpp

# Assume this is friend of Mystring class to access private attributes.
friend bool operator==(const Mystring &lhs, const Mystring &rhs);
 
bool operator==(const Mystring &lhs, const Mystring &rhs) {

    if (std::strcmp(lhs.str, rhs.str) == 0)
        return true;
    else
        return false;
}

```

### Overloading Stream Insertion / Extraction Operators
This allows us to read in and print out our classes.
These are not implemented as member methods because:
* Left operand is user-defined class
* Not the usual way we use these opeartors

```cpp

// Returns ostream by reference so we can keep inserting.
std::ostream &operator<<(std::ostream &os, const Mystring &obj) {
    os << obj.get_str(); // Or can use .str if friend function.
    return os;
}

std::istream &operator>>(std::istream &is, Mystring &obj) {
    char *buff = new char[1000];
    is >> buff;
    obj = Mystring{buff}; // If you have copy or move assignment
    delete [] buff;
    return is;
}

```

## Inheritance

### Inheritance vs. Composition

* Inheritance: "is-a" relationship 
* Composition: "has-a" relationship 

### Type Inheritance

* `public`
    * Most common
    * Establishes `is-a` relationship between derived and base class
* `private` / `protected`
    * Establishes `derived class has-a base class` relationship
    * `is implemented in terms of` relationship
    * Different from composition
    * Note: `private` members __are__ inherited, they are just not accessible.

```cpp
class Account {
    // Account class members
}

class Savings_Account: public Account {
    // Savings_Account class members
    // Savings_Account `is-a` Account
}


```
* `protected` allow access to base and derived classes, but not from instances of those objects.

```cpp

class Base {
    public: 
        int a{0};
        void display() {std::cout << a << b << c << endl;}
    protected:
        int b{0};
    private:
        int c{0}
};

class Derived : public Base {
    // c is inherited, but not accessible
    public:
        void access_base_members() {
            a = 100; // OK
            b = 200; // OK
            c = 300; // Compiler Error (not accessible)
        }
};

Base base;
base.a = 100; // OK
base.b = 200; // Compiler Error (protected accessible in derived class, but not from instances of the objects)
base.c = 300; // Compiler Error


Derived d;

d.a = 100; // OK
d.b = 200; // Compiler Error
d.c = 300; // Compiler Error

```

### Invoking Base Constructor

Call the base constructor in the initializer list.

```cpp
class Base {
    int value;
public:
    Base() : value{0} { 
        cout << "Base no args" << endl;
    };
    
    Base(int x) : value{x} { 
        cout << "int Base constructor" << endl; 
    }
};

class Derived : public Base {
    int doubled_value;

public:
    Derived(): Base{}, doubled_value{0} { 
        cout << "Derived no args" << endl; 
    }
    
    Derived(int x) : Base{x}, doubled_value{x*2} { 
        cout << "int Derived constructor" << endl; 
    }
};
```

### Copy / Move Constructors

* copy and move constructors are not explicitly inherited from the base class
* Can invoke base copy constructor explicitly

### Multiple Inheritance

C++ supports multiple inheritance.

```cpp
class Department_Chair: public Faculty, public Administrator {...};
```

### constexpr

`constexpr` are like constants that are only available within the class scope.
These can be used like constants that are only available within your class.
Example usage would be for default parameters.

```cpp
class Account {

private:
    static constexpr double def_balance = 0.0;
public:
    Account(double balance = def_balance);  
};
```

## Polymorphism

### Types of polymorphism

* Compile-time / early binding / static binding: All mean the same (happens at compile time)
* Run-time / late binding / dynamic binding: Happens at run time

Static binding is the default in C++.

Run-time polymorphism is available via:

* Inheritance
* Base class pointers or references
* Virtual functions

```cpp
Account *p = new Savings_Account();
p->withdraw(1000); // Calls Account::withdraw, NOT Savings_Account::withdraw()!

```
This is due to static binding: The compiler sees an `Account::withdraw` call, so calls that method, rather than the derived class method.

To solve, we can use runtime polymorphism.

### Virtual

To force run time polymorphism, we can use the `virtual` keyword in the base class.

This forces the compiler to check exactly what type of object we have a run time and call the appropriate method.

```cpp
Account *p = new Savings_Account();
p->withdraw(1000); // Calls Savings_Account::withdraw, IF withdraw has been marked virtual.

```

### Base Class Pointers & Virtual Functions

To use dynamic polymorphism, we need:

* Inheritance
* Base class pointer or base class reference
* Virtual functions

Using a base class pointer and virtual functions allows us to do runtime polymorphism.

Note: Virtual functions are dynamically bound __only__ when we call them via a base class pointer or reference. Otherwise they are statically bound.
```cpp
class Account {
public:
    virtual void withdraw(double amount) override;
};

class Checking_Account: public Account {
public:
    virtual void withdraw(double amount) override;
};

Account *p1 = new Account();
Account *p2 = new Savings_Account();

p1->withdraw(1000); // Calls Account::withdraw();
p2->withdraw(1000); // Calls Savings_Account::withdraw();

```

### Virtual Destructors

If a class has virtual functions, then it must __always__ provide a public virtual destructor.
Derived class destructors are also all virtual.

This means the derived class destructor will be called when the derived class is destroyed.

Note: `virtual` doesn't have to be included in the derived class, but is best practice.

```cpp
class Account {
public:
    virtual void withdraw(double amount);
    virtual ~Account();
};

class Checking_Account: public Account {
public:
    virtual void withdraw(double amount) override;
    virtual ~Checking_Account();
};
```

#### Override

`override` tells us that this function is meant to override the base class function. You can add this keyword, and the compiler will _ensure_ you are redefining the base class.

Just add `override` after the function definition.

```cpp
class Base {
public:
    virtual void say_hello() const;
};

class Derived: public Base {
public:
    virtual void say_hello() const override;
};
```

Note: `virtual` and `override` are just in the `.h` files, not the `.cpp` implementation files.

### Pure Virtual Functions & Abstract Classes

Pure virtual functions can be declared by adding ` = 0` in it's definition.
Any class with 1 or more pure virtual functions is abstract, and cannot be instantiated.

```cpp
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape();
};
```

### Abstract Classes as Interfaces

Abstract classes can be used as interfaces.
Interface classes are often prefixed with `I_`.

```cpp

// I_Printable.h
class I_Printable {
    friend ostream &operator<<(ostream &, const Printable &obj);
public:
    virtual void print(ostream &os) const = 0;
    virtual ~Printable() {};
};

// I_Printable.cpp
// Friend function implementation, not a member of the class.
ostream &operator<<(ostream &os, const Printable &obj) {
    obj.print(os);
    return os;
}

// Some_Class.h
class Some_Class : public I_Printable {
public:
    virtual void print(ostream &os) const override;
};

// Some_Class.cpp
void Some_Class::print(ostream &os) const {
        os << "Hi from Some_Class" ;
}
```

## Smart Pointers

The ultimate idea is that we can write code without using `new` or `delete`, and just have C++ clean up the memory when it's no longer needed.

### Issues with Raw Pointers

* Unitialized pointers
* Memory leaks
* Dangling pointers
* Not exception safe
* etc.

### Smart Pointers

Smart pointers are...

* Objects
* Can only point to heap-allocated memory
* Automatically call delete when no longer needed
* Adhere to RAII principles

There are three types:

1. Unique pointers (`unique_ptr`)
2. Shared pointers (`shared_ptr`)
3. Weak pointers (`weak_ptr`)

To create a smart pointer we must use `#include <memory>`.

Smart pointers are implemented as class templates.
They are wrappers around raw pointers.

### RAII
* __RAII__: Resource Acquisition Is Initialization
    * __Resource Acquisition__: Open a file, allocate memory
    * __Is Initialization__: Resource is acquired in a constructor

RAII objects are allocated on the stack.

### Unique Pointers

Simple, efficient smart pointer.

`unique_ptr<T>`
 * Points to an object of type T on the heap
 * Unique -- can only be one unique pointer pointing to this object on the heap
 * Owns what it points to
 * CANNOT be assigned or copied
 * CAN be moved
 * When it's destroyed, the thing it points to is destroyed too (i.e. when the pointer goes out of scope, the object that it points to on the heap will be destroyed)

```cpp

{
    std::vector<std::unique_ptd<int>> vec;
    std::unique_ptr<int> ptr {new int{100}};

    vec.push_back(ptr);  // Error: Copy not allowed
    vec.push_back(std::move(ptr));  // ptr gives up ownership of the pointer and moves it to the vector

    // OR
    std::unique_ptr<Test> t1{new Test(100)};
    std::unique_ptr<Test> t2;
    t2 = std::move(t1);

} // automatically deleted

```
More efficient to use `make_unique` -- no calls to `new` or `delete`.

```cpp
{
    std::unique_ptr<Account> p1 = std::make_unique<Account>("Curly", 500);
    auto p2 = make_unique<Player>("Hero", 100);
} // automatically deleted
```


### Shared Pointers

* Points to an object of type T on the heap
* Is not unique: multiple `shared_ptr`s can point to the same heap object
* CAN be assigned and copied
* CAN be moved
* When the use count is zero, the managed object on the heap is destroyed

```cpp
{
    std::shared_ptr<int> p1 {new int {100}};
    std::cout << *p1 << std::endl; // 100
    
    *p1 = 200; // OK
} // automatically deleted
```

Can also use `make_shared` to initialize:

* More efficient
* All 3 pointers point to the SAME heap object:
```cpp
{
    std::shared_ptr<int> p1 = std::make_shared<int>(100); // use_count=1
    std::shared_ptr<int> p2 {p1}; // use_count=2
    std::shared_ptr<int> p3;
    p3 = p1; // use_count =3
} // automatically deleted
```

### Weak Pointers

Provides a non-owning "weak" reference

* Points to an object of type T on the heap
* Does NOT participate in the owning relationship
* Always created from a `shared_ptr`
* Does NOT increment or decrement reference use count
* Used to prevent strong reference cycles which could prevent objects from being deleted

E.g.

```cpp
// A refers to B, and B refers to A
// So A keeps B alive, and B keeps A alive

class A:              class B:
  shared_ptr<B> ------> 
                <------ shared_ptr<A> 

```

Fix: Use `weak_ptr`

```cpp
// A refers to B, and B refers to A
// So A keeps B alive, but B DOES NOT keep A alive

class A:              class B:
  shared_ptr<B> ------> 
                <------ weak_ptr<A> 

```

### Custom Deleters

Not super common, but sometimes when we destroy a smart pointer, we need to do more than just destroy the object on the heap.

C++ smart pointers allow you to provide custom deleters.

#### Functions

Create a function that does some custom deletion logic, and then pass it in.

```cpp

void my_deleted(Some_Class *raw_pointer) {
    // Your custom deleter code
    delete raw_pointer;
}

shared_ptr<Some_Class> ptr { new Some_Class{}, my_deleted };
```

#### Lambdas

```cpp
shared_ptr<Test> ptr (new Test{100}, [] (Test *ptr) {
    cout << "Using custom deleter" << endl;
    delete ptr;
}



```

## Exception Handling

Best practices:
* Throw an object, not a primitive
* Throw by value
* Catch an object by reference (or const reference)

```cpp
// Define exceptions (can also throw primitives, but not best practice)
// DivideByZero.h
class DivideByZeroException : public std::exception{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept {
        return "Illegal balance exception";
    }
};

// Throw exception
double calculate_avg(int sum, int total) {
    if (total == 0) {
        throw DivideByZeroException{};
    }
    if (sum < 0) {
        throw NegativeValueException();
    }

    return static_cast<double>(sum) / total;
}

// Try...catch block
try {
    avg = calculate_avg(sum, total);
}
catch (const DivideByZeroException &ex) {
    std::cerr << ex.what() << std::endl;
}
catch (...) {
    std::cerr << "Caught unknown exception." << std::endl;
}
```

### Exception Hierarchy

* All exceptions inherit from `std::exception`
* All subclasses implement the `what()` virtual function that returns description
* `noexcept` tells the compiler the method will not throw an exception

## IO & Streams

Streams are an interface between the program and device. So we can just code to the stream interface. A stream is a sequence of bytes.

__Input__ streams provide data __to__ the program, and __output__ streams receive data __from__ the program.

```
Input Device --> {INPUT STREAM} --> Program --> {OUTPUT STREAM} --> Output Device
```

Common header files:
* `iostream`: Definitions for formatted input / output from/to streams
* `fstream`: Definitions for formatted input / output from/to file streams
* `iomanip`: Definitions for manipulators used to format stream I/O

### Stream Manipulators

Stream manipulators control the format of a stream.

```cpp
std::cout.width(10); // Member function
std::cout << std::setw(10); // manipulator version
```

```cpp
std::cout << std::boolalpha; // Will display true/false instead of 0/1

std::cout << (10 == 10) << std::endl; // Will display "true" instead of 1

std::cout << std::noboolalpha; // Toggle back to 0/1 instead of true/false
```

### File Streams

* Use `fstream` and `ifstream` objects.
* `ifstream` is used for input files only.
* Steps:
    * Connect the stream to a file on your file system (open for reading)
    * Read data via the stream
    * Close the stream
```cpp

# Open the file
# std::ios::in means open in input mode, can also open in binary mode with std::ios::binary
# std::ios::in | std::ios::binary: Open for input in binary mode.
std::fstream in_file {"../myfile.txt", std::ios::in };

# Alternative way to open:
std::ifstream in_file;
std::string filename;
std::cin >> filename; // get filename from the user

in_file.open(filename);

# Check if file opened successfully
    if (in_file.is_open()) {// Can also do if (infile) ...
    // Read from it...
} else {
    // File could not be opened...
}

# Read from the file (many ways to do this)
# File:
#  100
#  255.67
#  Larry
int num {};
double total {};
std::string name {};

in_file >> num;
in_file >> total >> name;

# Read line-by-line
std::string line{};
std::getline(in_file, line);

# Read all lines
while (!in_file.eof()) {
    std::getline(in_file, line);
    cout << line << std::endl;
}

# Or...
while (std::getline(in_file, line)) {
    cout << line << std::endl;
}

# Or...
while (in_file >> next_word) {
    // Read word by word...
}

# Close the file
in_file.close();

```


### Writing to files

* Use an `fstream` or `ofstream` object
* Connect it to a file on your file system (opens it for writing)
* Write data to the file
* Close the stream

Notes:
* Output files will be created if they don't exist
* Output files can be overwritten
* Can be opened to append
* `ofstream` is for output files only

```cpp
std::fstream out_file {"myfile.txt", std::ios::out};
std::ofstream out_file {"myfile.txt"}

std::string filename;
std::cin filename; // get the file name

out_file.open(filename);

if (out_file.isopen()) {
    // Read from it
} else {
    // File does not exist...
}

// Write to file
int num {100};

out_file << num << "\n" << std::endl;

// Close the file
out_file.close();
```

### String Streams

* Use in-memory strings as streams
* Allows us to read or write to in-memory strings as we would with files

* `include <sstream>`
* Connect string to a `sstream`

```cpp
#include <sstream>

int num{};
double total{};
std::string name{};
std::string inf {"Moe 100 1234.5"};

std::istringstream iss{info};
iss >> name >> num >> total;

# Write to string stream
int num {100};
double total {1234.5};
std::string name {"Moe"};

std::ostringstream oss{};
oss << name << " " << num << " " << total;
std::cout << oss.str() std::endl;
```

## STL

Huge class library implemented using templates and generic classes.

__Containers__
* Sequence containers
    * array
    * vector
    * list
    * forward_list
    * deque
* Associative containers
    * set
    * multi set
    * map
    * multi map
* Container adapters
    * stack
    * queue
    * priority queue

__Algorithms__

* Modifying
* Non-modifying

[cppreference.com](https://www.cppreference.com) can give good references.

### Generic Programming

#### Generic Programming with Macros (beware)

This is the inferior way to do it, but used in legacy C++ and C.

Simple `#define` your function, since `#define` does not require types.

```cpp
#define MAX(a, b) ((a > b) ? a : b)
std::cout << MAX(10, 20) << std::endl;
```


### Function Templates

The compiler generates the appropriate function / class from the blueprint (point: at compile time).

Code is not generated until the user uses the template.

```cpp
template <typename T>  // typename could also be "class", but they're the same

T max(T a, T b) {
    return (a > b) ? a : b;
}

int a {10};
int b {20};

std::cout << max<int>(a, b);
std::cout << max(a, b); // Compiler can also infer type of the template.
```

To get our own types to work with the generic function, it would have to overload the `<` operator.

Can also use multiple generic types:

```cpp
template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

func<int, double>(10, 20.2);
func(10, 20.2);
```

### Class Templates

```cpp
template <typename T, int N>  // Can be used to set size at init
                  // (set template param to type)


class Array {
    int size {N};
    T values[N]; // Needs to be known at compile time

public:
    Array() = default;
    Array(T init_val) {
        for(auto &item: values) {
            item = init_val;
        }
    }

    void fill(T val) {
        for(auto &item: values) {
            item = val;
        }
    }

    int get_size() const {
        return size;
    }

    T &operator[](int index) {
        return values[index];
    }
}

// Usage
Array<int, 5> nums;  // Need to provide both types

nums.fill(0);

nums[0] = 1000;

// Another
Array<int, 100> nums2(1);
```

### STL Containers

* Data structures that can store objects of almost any type
* Have specific member functions (`size`, `empty`, `insert`, and functions available to all containers
* To use comparative containers, we must overload the `<` and `==` operators

__Types of elements that can be stored in containers

* A _copy_ will be stored in the container, so elements should be...
* Copyable and assignable (copy constructor / move constructor)
* Moveable for efficiency (move constructor / move assignment)
* Ordered associative containers must be able to compare elements
    * `operator<`, `operator==`

#### STL Iterators

Allow us to process a sequence of elements in the container.

The syntax is `container_type::iterator_type iterator_name;`

```cpp
std::vector<int> vec {1, 2, 3};

std::vector<int>::iterator it1 = vec.begin();
// OR
auto it = vec.begin();

while (it != vec.end()) {
    std::cout << *it < " ";
    ++it;
}

// 1, 2, 3

// For loop syntax
for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << " ";
} // 1, 2, 3

// Reverse iterator
std::vector<int>::reverse_iterator it1 = vec.begin();

while (it != vec.end()) {
    std::cout << *it < " ";
    ++it;
} 

// 3, 2, 1
```

Containers have a beginning and end (`.begin()` and `.end()`). Begin is the first element, and end is the location __after__ the last element.

Calling either of these elements on the container (e.g. `vec.begin()`) returns an iterator pointing at, for example, the first element in the container.

### STL Algorithms

* STL algorithms work on sequences of container elements provided by an iterator

__Example Algorithms__

#### for-each

The `for_each` algorithm applies a function to each element in the iterator.
Function must be provided to the algorithm as:

* functor (function object)
* function pointer
* Lambda expression

```cpp
# Using function
struct Square_Functor {
    void operator()(int x) {  // overload () operator
        std::cout << x * x << " ";
    }
};

Square_Functor square;  // Function object

std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(), square);
// 1 4 9 16

// Using function pointer
void square(int x) {
    std::cout << x * x << " ";
}

std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(), square);
// 1 4 9 16

// Using lambda expression
std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(),
             [](int x) {std::cout << x * x << " ";})
// 1 4 9 16
```

### Sequence Containers

#### Arrays

* Use instead of raw arrays when possible

```cpp
std::array<int, 5> arr1 {1, 2, 3, 4, 5}; // C++11 requires double {{}}, C++14 does not

arr1.size();

arr1.front(); // 1
arr1.back();  // 5

arr1.empty(); // 0 (false)
int *data = arr.data(); // Get the raw array address
```

#### Vectors

```cpp
std::vector<int> vec1 {1, 2, 3};

vec.push_back(4);

vec.front(); // 1
vec.back();  // 4

std::vector<int> vec2 (10, 100); // ten 100s

vec1.size(); // 3
vec1.capacity(); // 3
vec1.max_size; // some very large number

vec.emplace_back("Larry", 18); // constructs person object and adds it to the vector.

auto it = std::find(vec1.begin(), vec1.end(), 3);
vec1.insert(it, 10); // 1, 2, 10, 3

it = std::find(vec1.begin(), vec1.end(), 2);
vec1.insert(it, vec2.begin(), vec2.end()); // insert sequence vec 2 into vec1 before 2. (1, 10, 10...10, 2, 10, 3)
```

#### Deque

* Constant time insertion at the back and front
* Elements are not stored in contiguous memory
* Implemented like a linked list of vector

```cpp
std::deque<int> d{1, 2, 3, 4, 5};
std::deque<int> d1(10, 100); // ten 100s

d.push_back(6);  // 1 2 3 4 5 6
d.pop_back();    // remove last element
d.push_front(0); // 0 1 2 3 4 5 6
d.pop_front();   // remove first element

d.emplace_back("Larry", 18);

// Other methods similar to vectors
```

#### List
* Sequence container
* Dynamic size
* Bidirectional (doubly linked)
* Direct access __not__ provided
* Rapid insertion and deletion of elements anywhere in the container
```
1 <-> 2 <-> 3
```
```cpp
std::list<int> l1 {1, 2, 3, 4, 5};
std::list<int> l2 (10, 100); // ten 100s

// Has the usual size, front, back methods
// Also supports push_back, pop_back, push_front, pop_front methods

// Iterator methods
auto it = std::find(l1.begin(), l.end(), 3);
l.insert(it, 10); // 1 2 10 3 4 5
l.erase(it); // erases 3 --> 1 2 10 4 5
l.resize(2); // 1 2
l.resize(5); // 1 2 0 0 0
```

#### Forward List
* Like list, but implemented as a singly-linked list
* Reverse iterators not available
* But less overhead

#### Sets

__set__
* Ordered by key
* Uses `operator<` to order elements and check if elements exist (find)

```cpp
std::set<int> s {1, 2, 3, 4, 5};

auto result = s.insert(7); // return std::pair<iterator, bool>
// This is an iterator to inserted element or duplicate in the set, and a bool indicating if insertion was successful.

s.erase(3); // 1 2 4 5 7

auto it = s.find(5); 
if (it != s.end()) {
    s.erase(it); // 1 2 4 7
}

s.empty(); // true or false

s1.count(3); // return 0 or 1 to find if element is in the set
```

__multi_set__
* Allows duplicate elements
* Can use `.count(x)` to get an idea of how many there are

__unordered_set__
* Elements are unordered
* No duplicates allowed
* Elements cannot be modified

__unordered_multiset__

#### Maps

__map__
* Elements are stored as Key, Value pairs `std::pair`
* Ordered by key

```cpp
std::map<std::string, int> m1 {
    {"Larry", 18},
    {"Moe", 25}
};

m1.size();

m1.insert(std::make_pair("Roger", 12));

m1["Frank"] = 21;    // insert
m1["Frank"] = 22;    // update
m1.at("Frank") = 23; // update, throw exception if not found

m1.erase("Anne");

if (m1.find("Larry") != m1.end()) {
    std::cout << "Found Larry!";
}

m1.count("Moe"); // Check if element exists
```

Other maps:
* multimap: Ordered by key with dupes
* unordered_map
* unordered_multimap

#### Stack

* LIFO
* Adapter: Implemented on top of other STL container (can be implemented as a vector, list or deque)
* No iterators supported

```cpp
std::stack<int> s;

// Since it's adapter, we can choose which implementation to use.
std::stack<int, std::vector<int>> s1;
std::stack<int, std::list<int>> s2;
std::stack<int, std::deque<int>> s3;

s.push(10);
s.pop();
s.push(20);
s.top(); // Returns ref without removing
s.empty();
s.size();
```

#### Queue

* FIFO
* Also an adapter class, like the stack (implemented on top of other containers)
* Elements pushed at the back and popped from the front

```cpp
std::queue<int> q;

q.push(10);
q.push(20);
q.push(30);

q.front(); // 10
q.back(); // 30

q.pop(); // removes 10
q.pop(); // removes 20

q.size();
```

#### Priority Queue

* Allows insertions and removals from front of the container
* Elements are invested in __priority__ order (largest value at the front)
* Container adapter data structure
* No iterators supported

```cpp
std::priority_queue<int> pq;

pq.push(10);
pq.push(20);
pq.push(4);

pq.top(); // 20 (largest)
pq.pop(); // remove 20
pq.top(); // 10 (now 10 is the largest)
```


## Lambda Expressions
* Lambda expressions generate function objectives behind the scenes

### Function Objects

* Declare by overloading the `()` (function call) operator

```cpp
struct Square_Functor {
    void operator() (int x) {
        std::cout << x * x << " ";
    }
};

Square_Functor square;
square(4); // Behind the scenes, calling: square.operator()(4); // Displays 16

std::vector<int> vec1 {1, 2, 3};

std::for_each(vec1.begin(), vec1.end(), square); // 1, 4, 9
```

### Lambdas

* Syntax: `[] () -> return_type specifiers { };`
    * `[]`: Beginning of lambda expression, capture list. Empty means it's a __stateless_ lambda expression
    * `()` :Parameter list
    * ` -> return_type`: The return type, can be omitted if void, and omitted to make compiler infer it
    * `specifiers` : Mutable and constexpr
    * `{ };`: The code
* 

```cpp
std::vector<int> vec1 {1, 2, 3, 4, 5};

std::for_each(vec1.begin(), vec1.end(), [](int x) { std::count << x << " "; });

// Assign to a variable
auto l = [] () { std::cout << "Hi"; };
l(); // Displays Hi

// Get a return type
auto l = [] (int x, int y) {return x + y};
std::cout << l(2, 3); // Displays 5

// Pass in the reference
[] (int &x) { std::cout << x; };

// Pass into STL function
std::vector<Person> people {
    {"Person 1", 18},
    {"Person 2", 20}
};

std::sort(begin(people), end(people), [](const Person &p1, const Person &p2) {
    return p1.get_name() < p2.get_name();
});
```

### Stateful Lambda Expressions

* Captures some information from its environment
* Can think of it like (actually it is), passing in the external parameter as a private variable to the class generated by the lambda by the compiler (the class captures this variable).
* Use `mutable` to modify variables captured by value (but will change a copy)
    * Can also capture variables by reference

```cpp
[captured_variables] () -> return_type specifiers { };
```

```cpp
// EXAMPLE 1: Mutable
int x {100};

auto l = [x] () mutable {
    x += 100;
    std::cout << x << std::endl;
};

l(); // Displays 200 (x is copied and changed)
std::cout << x << std::endl; // Displays 100 (original is shown)

l(); // Displays 300 (x COPY is incrmented again)
std::cout << x << std::endl; // Displays 100 (original is shown)

// EXAMPLE 2: By ref
int x {100};

auto l = [&x] () mutable { // Note also mutable
    x += 100;
    std::cout << x << std::endl;
};

l(); // Displays 200 (x is copied and changed)
std::cout << x << std::endl; // Displays 200 (ref was mutated)
```

### Lambdas & the STL

Most commonly, lambdas are used with the STL.

```cpp
std::vector<int> nums {10, 20, 30};

std::for_each(nums.begin(), nums.end(), [] (int num) {
    std::cout << num << " ";
});
```

## Enumerations

* Structure: `enum-key enum-name : enumerator-type { }; `

```cpp
enum Color {Red, Green, Blue}; // Implicitly assigned to 0, 1, 2
enum Color {Red=1, Green=2, Blue=3}; // Explicit initialization

Color my_color;
my_color = Green;

// Scoped Enumerations (Use the type in front)
enum class Item {Milk = 350, Bread = 250, Apple = 132 };
```
