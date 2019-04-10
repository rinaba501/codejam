#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

void solve(int n, int b, int f) {
    string input = "";
    vector<string> result(5, "");
    for (int i = 0; i < 5; ++i) {
        input = "";
        
        for (int j = 0; j < n/(int)pow(2,5-i); ++j) {
            input += string(pow(2,4-i), '0') + string(pow(2,4-i), '1');
        }
        if (n%(int)pow(2,5-i) <= pow(2,4-i)) {
            input += string(n%(int)pow(2,5-i), '0');
        } else {
            input += string(pow(2,4-i), '0') + string(n%(int)pow(2,5-i) - pow(2,4-i), '1');
        }
        cout << input << endl;
        cin >> result[i];
    }
    int numBroken = 0;
    for (int i = 0; i < n; ++i) {
        if( (result[0][i-numBroken] - '0') != (i/16)%2 ||
            (result[1][i-numBroken] - '0') != (i/8)%2 ||
            (result[2][i-numBroken] - '0') != (i/4)%2 ||
            (result[3][i-numBroken] - '0') != (i/2)%2 ||
            (result[4][i-numBroken] - '0') != (i/1)%2) {
            numBroken++;
            cout << i << " ";
        }
    }
    cout << endl;
    int verdict;
    cin >> verdict;
    if (verdict == -1) {
        exit(1);
    } 
}

int main() {
    int t, n, b, f;
    cin >> t;
    
    
    for (int i = 1; i <= t; ++i) {
        cin >> n >> b >> f;
        solve(n, b, f);
    }
}
