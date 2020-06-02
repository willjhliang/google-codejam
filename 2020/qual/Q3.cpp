
#include <bits/stdc++.h>

using namespace std;

pair<pair<int, int>, int> a[1010];
char b[1010];
void solve(int test) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a, a + n);
    int c = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first.first >= c) {
            c = a[i].first.second;
            b[a[i].second] = 'C';
        } else if (a[i].first.first >= j) {
            j = a[i].first.second;
            b[a[i].second] = 'J';
        } else {
            cout << "Case #" << test << ": IMPOSSIBLE" << endl;
            return;
        }
    }
    string ans = "";
    for (int i = 0; i < n; i++) ans += b[i];
    cout << "Case #" << test << ": " << ans << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
