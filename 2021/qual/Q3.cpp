
#include <bits/stdc++.h>

using namespace std;

int cost(int a[], int n) {
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        pair<int, int> m = make_pair(i, a[i]);
        for (int j = i + 1; j < n; j++) {
            if (a[j] < m.second) {
                m.first = j;
                m.second = a[j];
            }
        }
        res += (m.first - i + 1);
        reverse(a + i, a + m.first + 1);
    }
    return res;
}

void solve(int C) {
    int n, c; cin >> n >> c;
    if (n > 7)
        return;

    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    sort(a, a + n);

    cout << "Case #" << C << ": ";
    do {
        int b[n];
        copy(a, a + n, b);
        int curr = cost(b, n);
        if (curr == c) {
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            return;
        }
    } while (next_permutation(a, a + n));
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
