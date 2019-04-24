#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int T, C;

void solve() {
    vector<int> vec(C);
    vector<int> counts(C);
    bool is_right_position = false;

    for (int i = 0; i < C; ++i) {
        cin >> vec[i];
        counts[i] = vec[i];
        if (i) {
            counts[i] += counts[i-1];
        }
    }
    if (vec.front() == 0 || vec.back() == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> current_row(C);
    iota(current_row.begin(), current_row.end(), 1);

    string grid = "";
    
    int count = 0;
    while (!is_right_position) {
        count++;
        is_right_position = true;
        grid += ".";
        for (int j = 1; j < C - 1; ++j) {
            if (current_row[j-1] < counts[j-1]) {
                grid += "/";
                current_row[j-1]++;
                is_right_position = false;
            } else if (current_row[j] > counts[j]) {
                grid += "\\";
                current_row[j]--;
                is_right_position = false;
            } else {
                grid += ".";
            }
        }
        grid += ".\n";
    }
    cout << count << endl << grid;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> C;
        cout << "Case #" << t << ": ";
        solve();
    }
}