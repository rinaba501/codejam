#include <iostream>
#include <vector>
using namespace std;

int t, r, c, h, v, num_chips;
char ch;

bool possible (const vector<vector<int> > &grid, const vector<int> &row_counts) {
    if (num_chips % ((h + 1)*(v + 1)) != 0) return false;
    if (num_chips % (h + 1) != 0) return false;
    if (num_chips % (v + 1) != 0) return false;
    if (num_chips == 0) return true;
    int chips_per_h_cut = num_chips / (h+1);
    vector<int> h_cuts;
    int i = 0;
    while (i < r) {
        int count = 0;
        while (count < chips_per_h_cut) {
            count += row_counts[i];
            i++;
        }
        if (count > chips_per_h_cut) {
            return false;
        }
        h_cuts.push_back(i);
        while (i < r && !row_counts[i]) {
            i++;
        }
    }
    h_cuts.push_back(r);
    vector<int> cells(h+1, 0);
    int reached=0;
    int reached_count = 0;
    int chips_per_cell = num_chips / ((h + 1)*(v + 1));
    for (int i = 0; i < c; ++i) {
        int h_idx = 0;
        int j = 0;
        while (j < r) {
            while(j < h_cuts[h_idx]) {
                if (cells[h_idx] == chips_per_cell - 1 && grid[j][i]) {
                    reached++;
                }
                cells[h_idx] += grid[j][i];
                if (cells[h_idx] > chips_per_cell) {
                    return false;
                }
                j++;
            }
            h_idx++;
            if (h_idx > h) break;
        }
        if (reached == h + 1) {
            reached = 0;
            fill(cells.begin(), cells.end(), 0);
            reached_count++;
            if (reached_count == num_chips % ((h + 1)*(v + 1))) {
                return true;
            }
        }
    }
    return true;
}

int main () {
    cin >> t;
    
    for (int i = 1; i <= t; ++i) {
        cin >> r >> c >> h >> v;
        num_chips = 0;
        
        vector<vector<int> > grid (r, vector<int>(c, 0));
        vector<int> row_counts(r, 0);
        for (int a = 0; a < r; ++a) {
            for (int b = 0; b < c; ++b) {
                cin >> ch;
                if (ch == '@') {
                    grid[a][b]++;
                    num_chips++;
                    row_counts[a]++;
                }
            }
        }

        cout << "Case #" << i << ": ";
        if (possible(grid, row_counts)) {
            cout << "POSSIBLE\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }

    }
}