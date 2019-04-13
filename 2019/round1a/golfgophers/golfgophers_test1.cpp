#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAXC 1000
using namespace std;
typedef long long ll;

int T, N, M; 

int main() {
    cin >> T >> N >> M;
    for (int t=0; t < T; ++t){
        int sum = 0;
        int num = 0;
        for (int i = 0; i < 18; ++i) {
            cout << "18 ";
        }
        cout << endl;
        for (int i = 0; i < 18; ++i) {
                cin >> num;
                sum += num;
        }
        
        
        cout << sum << endl;
        int verdict;
        cin >> verdict;
        if (verdict == -1) {
            return -1;
        }
    }
    
}
