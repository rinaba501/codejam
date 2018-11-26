#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num_tests, num_dice;
    string pancakes;

    cin >> num_tests;

    for (size_t i = 0; i < num_tests; ++i) {
        cin >> num_dice;
        vector<vector<int> > vec(num_dice, vector<int>(6, -1));
        for (size_t j = 0; j < num_dice; ++j) {
            for (size_t k = 0; k < 6; ++k) {
                cin >> vec[j][k];
                cout << vec[j][k];
            }
            cout << endl;
        }
       
    }

    return 0;
}