
#include <iostream>

using namespace std;

void solve(int C) {
    int r, c; cin >> r >> c;
    r = r * 2 + 1;
    c = c * 2 + 1;
    cout << "Case #" << C << ": " << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0)) {
                cout << ".";
            } else if (i % 2 == 0 && j % 2 == 0) {
                cout << "+";
            } else if (i % 2 == 0 && j % 2 == 1) {
                cout << "-";
            } else if (i % 2 == 1 && j % 2 == 0) {
                cout << "|";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
