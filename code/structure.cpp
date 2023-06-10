#include <iostream>

using namespace std;

int main() {
//    int total {};
//    int num1 {}, num2 {}, num3 {};
//
//    const int count{3};
//
//    cout << "Enter 3 ints";
//
//    cin >> num1 >> num2 >> num3;
//
//    total = num1 + num2 + num3;
//
//    double average{0.0};
//
//    average = static_cast<double>(total) / count;
//
//    cout << "The 3 numbers were: " << num1 << ", " << num2 << ", " << num3 << endl;
//    cout << "The sum is: " << total << endl;
//    cout << "The avg is: " << average << endl;
//
//    cout << endl;

    int dollars{0};
    int quarters{0};
    int dimes{0};
    int nickels{0};
    int pennies{0};

    int amount{};

    cout << "Enter an amount in cents: " << endl;
    cin >> amount;

    while (amount > 0) {
        if (amount >= 100) {
            dollars += (amount / 100);
            amount %= 100;
        }
        else if (amount >= 25) {
            quarters += (amount / 25);
            amount %= 25;
        }
        else if (amount >= 10) {
            dimes += (amount / 10);
            amount %= 10;
        }
        else if (amount >= 5) {
            nickels += (amount / 5);
            amount %= 5;
        }
        else {  // 1
            pennies += amount;
            amount = 0;
        }
    }

    cout << "Dollars: " << dollars << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;

    return 0;
}