#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int X, Y;

template<typename T> T abs(const T& x) { return x < 0 ? -x : x; }
vector<vector<int>> seen;
vector<pair<int, int>> path;
bool doit(int x, int y, int n) {
  if (seen[y][x]) return false;
  seen[y][x]++;
  path.push_back({y+1, x+1});
  if (--n == 0) {
    return true;
  }
  vector<pair<int, int>> v;
  vector<pair<int, int>> pos;
  for (int y2 = 0; y2 < Y; y2++) if (y2 != y)
  for (int x2 = 0; x2 < X; x2++) if (x2 != x && abs(y2-y) != abs(x2-x)) {
    pos.push_back({x2, y2});
  }
  random_shuffle(pos.begin(), pos.end());
  for (auto p : pos) {
    if (doit(p.first, p.second, n)) return true;
  }
  seen[y][x]--;
  path.pop_back();
  return false;
}

int main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cin >> Y >> X;
    cout << "Case #" << prob++ << ": ";
    seen = vector<vector<int>>(Y, vector<int>(X));
    path.clear();
    if (doit(0, 0, X*Y)) {
      cout << "POSSIBLE" << endl;
      for (auto p : path) cout << p.first << ' ' << p.second << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }
}
