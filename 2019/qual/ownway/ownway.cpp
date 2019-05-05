#include <iostream>
using namespace std;

int main() {
    int t, n;
    string p, y;
    cin >> t;
    
    for (int x = 1; x <= t; ++x) {
        cin >> n >> p;
        y = "";
        for (char c : p) {
            if (c == 'E') {
                y += "S";
            }
            else {
                y += "E";
            }
        }
        cout << "Case #" << x << ": " << y << endl;
    }
}