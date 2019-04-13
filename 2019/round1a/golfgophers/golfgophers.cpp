#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, M; 

int main() {
    cin >> T >> N >> M;
    vector<int> vec{2,3,5,7,11,13,17};
    for (int t =0; t < T; ++t) {
        vector<int> remainders(7);
        int n = 0;
        int num = 0;
        int min = 0;
        for (auto num_b: vec) {
            for (int i = 0; i < 18; ++i) {
                cout << num_b << " ";
            }
            cout << endl;
            int sum = 0;
            for (int i = 0; i < 18; ++i) {
                cin >> num;
                sum += num;
            }
            min = max(min, sum);
            remainders[n] = sum % num_b;
            n++;
        }

        for (int i = 0; i <= M; ++i) {
            if (i%2 == remainders[0] && i%3 == remainders[1] && i%5 == remainders[2] &&
            i%7 == remainders[3] && i%11 == remainders[4] && i%13 == remainders[5] && 
            i%17 == remainders[6]) {
                cout << i << endl;
                break;
            }
        }
        int verdict;
        cin >> verdict;
        if (verdict == -1) {
            return -1;
        }
    }
    
}
