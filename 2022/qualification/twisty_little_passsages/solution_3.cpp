#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

uint64_t T, N, K, R, P, i;

void guess_passage_count() {
    cin >> N >> K;
    i = 0;
    cin >> R >> P;
    int first_room = R;
    u_int64_t num_passages = P;
    u_int64_t num_passages_2 = 0;
    unordered_set<int> u_set;
    for (int i = 1; i <= N; ++i) {
        if (i != first_room) {
            u_set.insert(i);
        }
    }
    u_int64_t k = 0;
    u_int64_t j = 0;
    u_int64_t l = 0;
    unordered_set<u_int64_t> visited_set;
    visited_set.insert(first_room);

    for (auto f : u_set) {
        if (visited_set.find(f) != visited_set.end()) {
            continue;
        }
        if (k == K) {
            break;
        }
        visited_set.insert(f);
        cout << "T " << f << endl;
        cin >> R >> P;
        num_passages += P;
        k++;
        j++;
        if (k == K) {
            break;
        }
        cout << "W" << endl;
        cin >> R >> P;
        num_passages_2 += P;
        k++;
        l++;
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
