#include <iostream>

using namespace std;

int main() {

    int room_width {0};
    int room_length {0};

    cout << "Enter the width of the room ";
    cin >> room_width;

    cout << "Enter the length of the room ";
    cin >> room_length;

    cout << "The area of the room is " << room_length * room_width << endl;

    return 0;
}