#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, M; 

int main() {
    cin >> T >> N >> M;
    vector<int> vec{5,7,9,11,13,16,17};
    for (int t =0; t < T; ++t) {
        vector<int> remainders(7);
        int n = 0;
        int num = 0;
        int min = 0;
        for (int num_b: vec) {
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
            int j = 0;
            for (; j < 7; ++j)
                if (i%vec[j] != remainders[j]) break;
            if (j == 7)  {
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
