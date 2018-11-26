#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num_tests, max_total_damage;
    string P;

    cin >> num_tests;

    for (size_t i = 0; i < num_tests; ++i) {
        cin >> max_total_damage >> P;
        cout << P << endl;
    }

    return 0;
}