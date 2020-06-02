#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
    int x, y; cin >> x >> y;
    string s; cin >> s;
    if (x == 0 && y == 0) {
        cout << "Case #" << test << ": " << 0 << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'N') y++;
        if (s[i] == 'S') y--;
        if (s[i] == 'E') x++;
        if (s[i] == 'W') x--;

        if (abs(x) + abs(y) <= (i + 1)) {
            cout << "Case #" << test << ": " << (i + 1) << endl;
            return;
        }
    }
    cout << "Case #" << test << ": " << "IMPOSSIBLE" << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
