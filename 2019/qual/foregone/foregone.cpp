#include <iostream>
using namespace std;

int main() {
    int t, c;
    string n, a, b;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        a = "";
        b = "";
        for (char c : n) {
            if (c == '4' || c == '5') {
                a += '3';
                b += '0' + c - '3';
            } else{
                a += c;
                if (!b.empty()) b += '0'; 
            }
        }
        cout << "Case #" << i + 1 << ": " << a << " " << b << endl;
    }
}