// Section 5
// Basic I/O using cin and cout

#include <iostream>

using namespace std;

int main() {
    // cout << "Hello, world!" << endl;

    // cout << "Hello";
    // cout << ", World!" << endl;

    int num1;
    int num2;
    double num3;

//    cout << "Enter an integer ";
//    cin >> num1;
//    cout << "You entered: " << num1 << endl;
//
//    cout << "Enter an integer";
//    cin >> num1;
//
//    cout << "Enter another integer";
//    cin >> num2;
//
//    cout << "You entered " << num1 << " and " << num2 << endl;

    cout << "Enter 2 integers separated by a space ";
    cin >> num1 >> num2;

    cout << "You entered " << num1 << " and " << num2 << endl;

    return 0;
}