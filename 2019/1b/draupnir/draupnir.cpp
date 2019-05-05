#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int T, W; 

int main() {
    cin >> T >> W;
    for (int t=0; t < T; ++t){
        ll n1, n2;
        cout << 200 << endl;
        cin >> n1;
        cout << 56 << endl;
        cin >> n2;
        vector<ll> vec(6);
        vec[3] = n1 >> 50;
        vec[4] = n1%(2ll << 49) >> 40;
        vec[5] = n1%(2ll << 39) >> 33;
        
        ll sum = (vec[5] << 9) + (vec[4] << 11) + (vec[3] << 14);
        vec[0] = (n2 - sum) >> 56;
        vec[1] = (n2 - sum)%(2ll << 55) >> 28;
        vec[2] = (n2 - sum)%(2ll << 27) >> 18;
        
        for (ll val : vec) {
            cout << val << " ";
        }
        cout << endl;
    
        int verdict;
        cin >> verdict;
        if (verdict == -1) {
            return -1;
        }
    }
    
}
