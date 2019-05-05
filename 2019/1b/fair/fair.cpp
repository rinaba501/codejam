#include <iostream>
#include <vector>
using namespace std;
int T, P, Q;


void solve() {

}

int main() {
    // added the two lines below 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        cin >> P >> Q;
        cout << "Case #" << t << ": ";
        solve();
        cout << "\n";
    }
}