#include <iostream>
using namespace std;
int T;

#define MAXN 505
#define MAXCHAIN 40

int memo[MAXN][MAXN][MAXCHAIN];

int solve(int R, int B, int r) {
  int& ref = memo[R][B][r];
  if (ref != -1) return ref;

  ref = 0;
  for (int b = 1; b * (b - 1) / 2 <= B && r * b <= R; b++) {
    ref = max(ref, b + solve(R - r * b, B - b * (b - 1) / 2, r + 1));
  }

  return ref;
}

int main() {
    // added the two lines below 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    memset(memo, -1, sizeof(memo));
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int R, B;
        cin >> R >> B;
        cout << "Case #" << t << ": " << solve(R, B, 0) << "\n";
    }
}