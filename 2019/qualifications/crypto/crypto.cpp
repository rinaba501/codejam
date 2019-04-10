#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;

void find_factors(__int128 num, int n, int &a, int &b) {
    for (int i = 2; i <= n; ++i) {
        if (num % i == 0) {
            a = i;
            b = num/i;
            return;
        }
    }
}

int main() {
    int t, n, l, num;
    string result = "";
    int a, b;

    cin >> t;
    for (int i = 1; i <= t; ++i) {
        vector<int> sol;
        vector<int> rev;
        pair<int, int> stack_top;
        unordered_set<int> seen;
        int need_to_fix = 2;
        int prev = 0;
        result = "";
        cin >> n >> l;
        for (int j = 0; j < l; ++j) {
            cin >> num;
            if (j == 0) {
                find_factors(num, n, a, b);
                seen.insert(a);
                seen.insert(b);
            } else {
                if (need_to_fix == 0) {
                    prev = num/prev;
                    sol.push_back(prev);
                    seen.insert(prev);
                } else if (num % b == 0  && num % a == 0 && a != b) {
                    need_to_fix++;
                } else if (num % a == 0) {
                    while (need_to_fix > 0) {
                        if (need_to_fix % 2) {
                            sol.push_back(a);
                        } else {
                            sol.push_back(b);
                        }
                        need_to_fix--;
                    }
                    b = num/a;
                    sol.push_back(b);
                    seen.insert(b);
                    prev = b;
                    
                } else if (num % b == 0) {
                    while (need_to_fix > 0) {
                        if (need_to_fix % 2) {
                            sol.push_back(b);
                        } else {
                            sol.push_back(a);
                        }
                        need_to_fix--;
                    }
                    a = num/b;
                    sol.push_back(a);
                    seen.insert(a);
                    prev = a;
                }
            }
        }
        std::set<int> ordered(seen.begin(), seen.end());
        unordered_map<int, char> c_map;
        int a= 0;
        for (auto iter = ordered.begin(); iter != ordered.end(); ++iter)
        {
            c_map[*iter] = 'A' + a;
            a++;
        }

        for (int j = 0; j < sol.size(); ++j) {
            result += c_map[sol[j]];
        }
        std::cout << "Case #" << i << ": " << result << endl;
    }
}