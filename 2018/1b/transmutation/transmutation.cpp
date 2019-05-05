#include <iostream>
#include <vector>
using namespace std;

int T, M;
typedef long long ll;

ll solve() {
    vector<vector<int> > vec(M, vector<int>(2,0));
    for (int i = 0; i < M; ++i) {
        cin >> vec[i][0] >> vec[i][1];
    }
    vector<int> num_elements(M);
    for (int i =0; i < M; ++i) {
        cin >> num_elements[i];
    }
    return 0;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> M;
        cout << "Case #" << t << ": " << solve() << endl;
    }
}