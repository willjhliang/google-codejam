
#include <bits/stdc++.h>

using namespace std;


void solve(int C) {
    long long a[30];
    long long b[100];
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    cout << "Case #" << C << ": ";

    long long n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        long long l = a[i + 1] - a[i];
        if (l % 2 == 0) {
            b[j++] = l / 2;
            b[j++] = l / 2 - 1;
        } else {
            b[j++] = (l - 1) / 2;
            b[j++] = (l - 1) / 2;
        }
    }
    b[j++] = a[0] - 1;
    b[j++] = k - a[n - 1];
    sort(b, b + j);

    long long s = b[j - 1] + b[j - 2];
    cout << (float)s / k << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
