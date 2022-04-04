#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

u_int64_t T, N, K, R, P, i;

void guess_passage_count() {
    cin >> N >> K;
    i = 0;
    cin >> R >> P;
    u_int64_t first_room = R;
    u_int64_t num_passages = P;
    u_int64_t num_passages_2 = 0;
    if (first_room <= K) {
        K++;
    }
    unordered_set<u_int64_t> visited_set;
    visited_set.insert(first_room);
    u_int64_t j = 0;
    u_int64_t k = 0;
    u_int64_t l = 0;

    for (i = 1; i <= N && k < K; ++i) {
        while (visited_set.find(i) == visited_set.end() && i <= N) {
            i++;
        }
        if (i > N) {
            break;
        }
        visited_set.insert(i);
        cout << "T " << i << endl;
        k++;
        j++;
        cin >> R >> P;
        num_passages += P;
        if (k == K) {
            break;
        }
        cout << "W" << endl;
        k++;
        l++;
        cin >> R >> P;
        num_passages_2 += P;
        visited_set.insert(R);
    }

    u_int64_t visited = num_passages + num_passages_2;
    u_int64_t aa = max((u_int64_t)0, N - K);
    cout << "E " << (u_int64_t)(visited / 2 + num_passages * aa / j / 2)
         << endl;
}

int main() {
    cin >> T;
    for (int t = 0; t < T; ++t) {
        guess_passage_count();
    }
    return 0;
}
