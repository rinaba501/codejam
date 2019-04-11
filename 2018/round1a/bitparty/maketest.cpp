#include <iostream>
using namespace std;

void generate_testcases(int R, int B, int C) {
    cout << R << " " << B << " " << C << endl;
    int mi, mi_added = 0;
    for (int i = 0; i < C -1; ++i) {
        mi = rand()%10 + 1;
        mi_added += mi;
        cout << mi << " " << rand()%20 + 1 << " " << rand()%20 + 1 << endl;
    }
    cout << rand()%10 + abs(mi_added - B) << " " << rand()%20 + 1 << " " << rand()%20 + 1 << endl;
    cout << endl;
}

int main() {
    int num_tests = 5;
    cout << num_tests << endl << endl;
    for (int i =0; i < num_tests; ++i) {
        generate_testcases(4, 18, 4);
    }
    
}