#include <bits/stdc++.h>

using namespace std;

char f[4] = {'N', 'S', 'E', 'W'};

string jump(int x, int y, int k, string s) {
    if (x == 0 && y == 0) return s;

    int bx = (1 << k) & x, by = (1 << k) & y;
    if ((bx > 0 && by > 0) || (bx == 0 && by == 0)) return "";
    if (bx > 0) {
        string ss = jump(x - (1 << k), y, k + 1, s + f[2]);
        if (ss != "") return ss;
        ss = jump(x + (1 << k), y, k + 1, s + f[3]);
        return ss;
    } else {
        string ss = jump(x, y - (1 << k), k + 1, s + f[0]);
        if (ss != "") return ss;
        ss = jump(x, y + (1 << k), k + 1, s + f[1]);
        return ss;
    }
}

void solve(int test) {
    int x, y; cin >> x >> y;
    f[0] = 'N'; f[1] = 'S'; f[2] = 'E'; f[3] = 'W';
    if (x < 0) swap(f[2], f[3]);
    if (y < 0) swap(f[0], f[1]);
    x = abs(x); y = abs(y);

    string s = jump(x, y, 0, "");
    cout << "Case #" << test << ": " << (s == "" ? "IMPOSSIBLE" : s) << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
