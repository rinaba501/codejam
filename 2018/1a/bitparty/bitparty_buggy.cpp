#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <unordered_map>
using namespace std;

int T, R, B, C;

class Cashier {
public:
    int m;
    int s;
    int p;
    int num_bits;
    int cost;
};

struct cmp {
    bool operator()(Cashier left, Cashier right) { 
        return (left.cost) > (right.cost);
    };
};

int solve() {
    priority_queue<Cashier, vector<Cashier>, cmp > pq;
    Cashier cash = Cashier();
    for (int i = 0; i < C; ++i) {
        cin >> cash.m >> cash.s >> cash.p;
        cash.cost = cash.p + cash.s;
        cash.num_bits = 0;
        pq.push(cash);
    }

    vector<int> nums(B, 0);
    int sum = 0;
    while (sum < B) {
        cash = pq.top();
        pq.pop();
        nums[cash.num_bits]++;
        if (nums[cash.num_bits] <= R) {
            sum++;
            if (sum == B) return cash.cost;
        }
        cash.m--;
        cash.num_bits++;
        if (cash.m) {
            cash.cost += cash.s;
            pq.push(cash);
        }
    }
    return -1;
}

int main () {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> R >> B >> C;
        cout << "Case #" << t << ": " << solve() << endl;
    }
}