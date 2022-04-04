#include <iostream>
using namespace std;

int T, A, B, C, D, a, b, c, d;

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        a = 1e6;
        b = 1e6;
        c = 1e6;
        d = 1e6;
        for (int i = 0; i < 3; ++i) {
            cin >> A >> B >> C >> D;
            a = min(A, a);
            b = min(B, b);
            c = min(C, c);
            d = min(D, d);
        }
        if (a + b + c + d < 1e6) {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        } else {
            int remaining = 1e6;
            a = min(a, remaining);
            remaining -= a;
            b = min(b, remaining);
            remaining -= b;
            c = min(c, remaining);
            remaining -= c;
            d = min(d, remaining);
            cout << "Case #" << t << ": " << a << " " << b << " " << c << " "
                 << d << endl;
        }
    }
    return 0;
}