#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int T, N, K, R, P, i;

void guess_passage_count() {
    cin >> N >> K;
    i = 0;
    cin >> R >> P;
    int first_room = R;
    u_int64_t num_passages = P;
    if (first_room >= N + 1 - K) {
        K++;
    }

    for (i = 1; i <= K && i <= N; ++i) {
        // cout << i << endl;
        if (N + 1 - i == first_room) {
            continue;
        }
        cout << "T " << N + 1 - i << endl;
        cin >> R >> P;
        num_passages += P;
    }
    if (N <= K) {
        cout << "E " << num_passages / 2 << endl;
        return;
    }

    u_int64_t passages = (N - 1) * K;
    u_int64_t missed_passages = (N - 1) * K - num_passages;
    uint64_t max_passages = (N - 1) * N / 2;
    uint64_t lower_bound = num_passages / 2;
    uint64_t upper_bound = max_passages - missed_passages / 2;
    // cout << "missed: " << missed_passages << endl;
    // cout << "passages: " << passages << endl;
    // cout << "num passages " << num_passages << endl;
    // cout << "max passages " << max_passages << endl;
    // cout << "estimate " << max_passages * num_passages / passages << endl;
    cout << "E " << max_passages * num_passages / passages << endl;
}

int main() {
    cin >> T;
    for (int t = 0; t < T; ++t) {
        guess_passage_count();
    }
    return 0;
}
