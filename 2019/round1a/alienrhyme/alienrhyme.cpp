#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int T, N; 

int solve() {
    vector<string> vec(N);
    int count = 0;
    int max_len = 0;
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
        reverse(vec[i].begin(), vec[i].end());
        max_len = max(max_len, (int)vec[i].length());
    }
    unordered_map<string, int> seen;
    unordered_set<int> included;
    for (int i = max_len; i > 0; --i) {
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j].length() < i) continue;
            string cur = vec[j].substr(0,i);
            // cout << cur << endl;
            if (included.find(j) != included.end()) continue;
            if (seen.find(cur) == seen.end()) {
                seen[cur] = j;
            } else if (seen[cur] != -1) {
                count += 2;
                included.insert(seen[cur]);
                included.insert(j);
                seen[cur] = -1;
            }
        }
    }
    return count;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
