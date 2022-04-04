#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int T, N;

int main() {
    cin >> T;
    vector<int> vec(1e5);

    for (int t = 1; t <= T; ++t) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.begin() + N);

        int j = 0;
        int count = 0;
        while (j < N) {
            if (count < vec[j]) {
                count++;
            }
            j++;
        }

        cout << "Case #" << t << ": " << count << endl;
    }
}