
#include <bits/stdc++.h>

using namespace std;


void solve(int C) {
    int a[100000];
    memset(a, 0, sizeof a);

    cout << "Case #" << C << ": ";

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    int lo = 0;
    int hi = n - 1;
    int m = 0;
    while (lo <= hi) {
        if (a[lo] < a[hi]) {
            if (a[lo] >= m) {
                res++;
                m = a[lo];
            }
            lo++;
        } else {
            if (a[hi] >= m) {
                res++;
                m = a[hi];
            }
            hi--;
        }
    }
    cout << res << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
