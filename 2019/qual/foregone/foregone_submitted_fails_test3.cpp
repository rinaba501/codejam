#include <iostream>
using namespace std;

int main() {
    int t, n, a, b, c;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        a = 0;
        b = 0;
        int j = 1;
        while (n != 0) {
            c = n % 10;
            if (c == 4 || c == 5) {
                a += 3*j;
                b += (c-3)*j;
            }
            else {
                a += c * j;
            }
            
            n /= 10;
            j *= 10;
        }
        cout << "Case #" << i + 1 << ": " << a << " " << b << endl;
    }
}