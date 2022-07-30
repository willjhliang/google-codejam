
#include <bits/stdc++.h>

using namespace std;


void solve(int C) {
    cout << "Case #" << C << ": ";

    int n, k; cin >> n >> k;

    long long a = 0;
    long long b = 0;
    for (int i = 0; i < n; i++) {
        long long c; cin >> c;
        a += c;
        b += c * c;
    }

    if (a == 0 && b == 0) {
        cout << 0 << endl;
        return;
    }
    if (a == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    long long top = b - a * a;
    if (top % 2 != 0 || top % a != 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << (top / 2) / a << endl;
    }
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
