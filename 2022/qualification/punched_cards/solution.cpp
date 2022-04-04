#include <iostream>
using namespace std;

int T, R, C;

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> R >> C;
        string s = ".";
        string n = "+", m = ".|", o;
        for (int c = 1; c < C; ++c) {
            n += "-+";
            m += ".|";
        }
        s += "." + n;
        s += "\n." + m;
        n = "\n+-" + n;
        m = "\n|" + m;

        for (int r = 1; r < R; ++r) {
            s += n + m;
        }
        s += n;
        cout << "Case #" << t << ":\n" << s << endl;
    }

    return 0;
}