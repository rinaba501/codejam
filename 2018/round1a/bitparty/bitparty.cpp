#include <iostream>
#include <cmath>
#include <algorithm>

#define MAXC 1000
using namespace std;
typedef long long ll;

ll M[MAXC], S[MAXC], P[MAXC], max_items[MAXC];
int T; 
ll R, B, C; 

ll solve() {
    for (int i = 0; i < C; i++) {
        cin >> M[i] >> S[i] >> P[i];
    }

    ll min_time = 1;
    ll max_time = powl(10, 18) + powl(10, 9);
    ll curr_time;

    while (min_time < max_time) {
        curr_time = (min_time + max_time)/2;
        for (int i = 0; i < C; i++) {
            ll items = max(0ll, curr_time - P[i]) / S[i];
            max_items[i] = max(0ll, min(M[i], items));
        }

        sort(max_items, max_items + C, greater<ll>());
        ll total = 0;
        for (int i = 0; i < R; i++) {
            total += max_items[i];
        }
        if (total >= B)  max_time = curr_time;
        else min_time = curr_time + 1;
    }
    return min_time;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> R >> B >> C;
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
