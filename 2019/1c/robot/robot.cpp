#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, A;

string solve() {
    vector<string> vec(A);
    vector<int> alive(A, 1);

    // O rock, 1 paper, 2 scissor
    vector<bool> moves(3); 
    vector<char> beats{'P','S', 'R'};
    string so_far = "";

    for (int i = 0; i < A; ++i) cin >> vec[i];
    
    for (int i = 0; i < 500; ++i) {
        fill(moves.begin(), moves.end(), false);

        for (int j = 0; j < A; ++j) {
            if (alive[j]) {
                char move = vec[j][i%vec[j].length()];
                if (move == 'R') moves[0] = true;
                else if (move == 'P') moves[1] = true;
                else moves[2] = true;
            }
        }
        int count = 0;
        for (int j = 0; j < 3; ++j) { 
            count += moves[j];
        }
        if (count == 3) return "IMPOSSIBLE";
        if (count == 1) {
            for (int j = 0; j < 3; ++j)
                if (moves[j]) return so_far + beats[j];
        }
        int no_move;
        for (int j = 0; j < 3; ++j)
            if (!moves[j]) no_move = j;
        
        for (int j = 0; j < A; ++j) {
            int hand = 2;
            char move = vec[j][i%vec[j].length()];
            if (move == 'R') hand = 0;
            else if (move == 'P') hand = 1;

            alive[j] = min(alive[j], (int)((no_move +1)%3 != hand));
        }
        so_far += beats[(no_move+1)%3];
    }

    return "IMPOSSIBLE";
}

int main() {
    // added the two lines below 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        cin >> A;
        cout << "Case #" << t << ": " << solve() << "\n";
    }
}