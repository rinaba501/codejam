#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAXC 1000
using namespace std;
typedef long long ll;

int T, R, C;

void backtrack(vector<int> result) {
    if

}

vector<int> solve() {
    vector<int> vec (R*C);
    vector<int> result{1,2,6};
    for (int i = 0; i < R*C; ++i) {
        if 
    }
    return result;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> R >> C;
        vector<int> vec = solve();
        if (vec.empty()) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        } else{
            cout << "Case #" << t << ": POSSIBLE" << endl;
            for (auto v: vec) {
                cout << v/C << " " << v%C << endl;
            }
        }
    }
}
