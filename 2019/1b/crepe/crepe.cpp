#include <iostream>
#include <vector>
using namespace std;
int T, P, Q;

int find_inter(vector<int> vec) {
    int max_idx = -1;
    int max_count = -1e6;
    int cur = 0;

    for (int i = 0; i <= Q; ++i) {
        cur += vec[i];
        if (cur > max_count) {
            max_idx = i;
            max_count = cur;
        }
    }
    return max_idx;
}

void solve() {
    vector<int> x_vec(Q + 1);
    vector<int> y_vec(Q + 1);
    int x, y;
    char dir;

    for (int i = 0; i < P; ++i) {
        cin >> x >> y >> dir;
        if (dir == 'N') y_vec[y+1]++;
        else if (dir == 'S') y_vec[y]--;
        else if (dir == 'E') x_vec[x+1]++;
        else x_vec[x]--;
    }

    cout << find_inter(x_vec) << " " << find_inter(y_vec) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        cin >> P >> Q;
        cout << "Case #" << t << ": ";
        solve();
    }
}