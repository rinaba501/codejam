#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int num_tests, size;
    cin >> num_tests;

    for (size_t i = 0; i < num_tests; ++i) {
        cin >> size;
        vector<int> nums(size, -1);
        vector<int> even_nums((size + 1)/2, -1);
        vector<int> odd_nums(size/2, -1);

        int j = 0;
        for (; j < size; ++j) {
            cin >> nums[j];
            if (j&1) {
                odd_nums[j/2] = nums[j];
            } else {
                even_nums[j/2] = nums[j];
            }
        }
        sort(nums.begin(), nums.end());
        sort(even_nums.begin(), even_nums.end());
        sort(odd_nums.begin(), odd_nums.end());
        int min = size;

        for (j = 0; j < size; ++j) {
            if ((j & 1) && nums[j] != odd_nums[j/2]) {
                cout << "Case #" << i + 1 << ": " << j << "\n";
                break;
            } else if (!(j & 1) && nums[j] != even_nums[j/2]) {
                cout << "Case #" << i + 1 << ": " << j << "\n";
                break;
            }
        }
        if (j == size) {
            cout << "Case #" << i + 1 << ": OK\n";
        }
        
    }

    return 0;
}