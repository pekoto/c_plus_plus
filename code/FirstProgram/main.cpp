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
    std::cout << "No, really!" << favourite_number << " is my favourite number!" << std::endl;


    return 0;
}