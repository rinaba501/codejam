#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    cout << "3" << endl;
    for (int t = 0; t < 3; ++t) {
        cout << "10" << endl;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << (char)('A' + rand()%5);
            }
            cout << endl;
        }
    }
}