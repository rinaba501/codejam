#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num_tests, flipper_size, flip_count;
    string pancakes;

    cin >> num_tests;

    for (size_t i = 0; i < num_tests; ++i) {
        cin >> pancakes >> flipper_size;
        size_t j = 0;
        flip_count = 0;
        
        for (; j <= pancakes.length() - flipper_size; ++j) {
            if (pancakes[j] == '-') {
                flip_count++;
                for (size_t k = 0; k < flipper_size; ++k) {
                    if (pancakes[j + k] == '-') {
                        pancakes[j + k] = '+';
                    } else {
                        pancakes[j + k] = '-';
                    }
                }
            }
        }
        for (; j < pancakes.length(); ++j) {
            if (pancakes[j] == '-') {
                cout << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
                break;
            }
        }
        if (j == pancakes.length()) {
            cout << "Case #" << i + 1 << ": " << flip_count << endl;
        }
    }

    return 0;
}