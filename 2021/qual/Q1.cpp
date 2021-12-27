
#include <bits/stdc++.h>

using namespace std;

int a[200];

void solve(int C) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
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
    
    cout << "Case #" << C << ": " << res << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
