#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void backtrack(int cur_idx, double current, double buffer, double &best, const int &P, 
               const vector<vector<int> > &cookies, const int &N) {
    if (best == P) return;
    if (current > P) return;
    if (current + buffer >= P && P >= current) {
        best = P; 
        return;
    }
    if (current + buffer > best) best = current + buffer;
    if (cur_idx == N) return;
    double min_cut = min(cookies[cur_idx][0], cookies[cur_idx][1]);
    double max_cut = sqrt(pow(cookies[cur_idx][0], 2) + pow(cookies[cur_idx][1], 2));
    backtrack(cur_idx + 1, current + 2*min_cut, buffer + 2*(max_cut - min_cut), best, P, cookies, N);
    backtrack(cur_idx + 1, current, buffer, best, P, cookies, N);
}

double solve(int N, int P) {
    vector<vector<int> > cookies(N, vector<int>(2));
    double best = 0;
    double diagonals = 0;
    for (int i = 0; i < N; ++i) {
        cin >> cookies[i][0] >> cookies[i][1];
        best += 2*(cookies[i][0] + cookies[i][1]);
        diagonals += 2*sqrt(pow(cookies[i][0], 2) + pow(cookies[i][1], 2));
    }
    if (diagonals + best <= P) {
        return diagonals + best;
    }
    backtrack(0, best, 0, best, P, cookies, N);
    return best;
}

int main() {
    int T, N, P;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> N >> P;
        cout << setprecision(6) << fixed << "Case #" << t << ": " << solve(N, P) << endl;
    }
}