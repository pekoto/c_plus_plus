// Section 7
// Vectors

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // 5 initialized to zero
    // vector <char> vowels (5);

    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};

    cout << vowels[0] << endl;

    // 3 elements initialized to 100
    // vector <int> test_scores (3, 100);

    // 3 elements initialized explicitly
    vector <int> test_scores {100, 98, 99};

    cout << test_scores.at(0) << endl;

    cout << test_scores.size() << endl;

    int new_score {0};

    // cin >> new_score;

    test_scores.push_back(new_score);

    cout << test_scores.size() << endl;

    vector<vector<int>> movie_ratings {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };

    cout << movie_ratings[0][1] << endl;

    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "Vector 1, element 0 : " << vector1.at(0) << endl;
    cout << "Vector 1, element 1 : " << vector1.at(1) << endl;
    cout << "Vector 1, size : " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "Vector 2, element 0 : " << vector2.at(0) << endl;
    cout << "Vector 2, element 1 : " << vector2.at(1) << endl;
    cout << "Vector 2, size : " << vector2.size() << endl;

    vector<vector<int>> vector2d;

    vector2d.push_back(vector1);
    vector2d.push_back(vector2);

    cout << "vector 2d element 0: " << vector2d.at(0).at(0) << endl;
    cout << "vector 2d element 1: " << vector2d.at(0).at(1) << endl;
    cout << "vector 2d element 2: " << vector2d.at(1).at(0) << endl;
    cout << "vector 2d element 3: " << vector2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;

    cout << "vector 2d element 0: " << vector2d.at(0).at(0) << endl;

    cout << "Vector 1, element 0 : " << vector1.at(0) << endl;
    cout << "Vector 1, element 1 : " << vector1.at(1) << endl;

    return 0;
}
