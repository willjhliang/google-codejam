
#include <bits/stdc++.h>

using namespace std;

long long v[200];

void solve(int C) {
    int n; cin >> n;
    int m = 29;
    memset(v, 0, sizeof v);
    int idx = 0;

    for (int i = 0; i <= m; i++) {
        cout << (1 << i) << " ";
    }
    for (int i = m + 1; i < n; i++) {
        cout << 2 * i + 1 << " ";
        v[idx++] = 2 * i + 1;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        long long a; cin >> a;
        v[idx++] = a;
    }

    long long s1 = 0;
    long long s2 = 0;
    sort(v, v + idx);
    for (int i = 0; i < idx; i++) {
        if (s1 < s2) {
            s1 += v[i];
            cout << v[i] << " ";
        } else {
            s2 += v[i];
        }
    }
    for (int i = m; i >= 0; i--) {
        if (s1 < s2) {
            s1 += (1 << i);
            cout << (1 << i) << " ";
        } else {
            s2 += (1 << i);
        }
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
