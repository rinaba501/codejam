#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num_tests, max_total_damage;
    string P;

    cin >> num_tests;

    for (size_t i = 0; i < num_tests; ++i) {
        cin >> max_total_damage >> P;
        vector<int> vals;
        int damage = 1;
        int total_damage = 0;
        for (char c : P) {
            if (c == 'C') {
                damage *= 2;
            } else {
                vals.push_back(damage);
                total_damage += damage;
            }
        }
        int length = vals.size();
        if (length > max_total_damage) {
            cout << "Case #" << i + 1 << ": IMPOSSIBLE\n";
        } else {
            int hack_count = 0;
            int idx = length;
            while (total_damage > max_total_damage) {
                if (idx == length) {
                    int curr_max_damage = vals[length - 1];
                    idx = length - 1;
                    while(idx && vals[idx - 1] == curr_max_damage) {
                        idx--;
                    }
                }
                vals[idx] /= 2;
                total_damage -= vals[idx];
                ++idx;
                hack_count++;
            }
            cout << "Case #" << i + 1 << ": " << hack_count << "\n";
        }
    }

    return 0;
}