
#include <bits/stdc++.h>

using namespace std;

void solve(long long C) {
    long long a[1000][100];
    long long dp[1000][2];
    memset(a, 0, sizeof a);
    memset(dp, 0, sizeof dp);

    cout << "Case #" << C << ": ";

    int n, p; cin >> n >> p;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> a[i][j];
        }
        sort(a[i], a[i] + p);
        s += a[i][p - 1] - a[i][0];
    }

    dp[0][1] = a[0][0];
    dp[0][0] = a[0][p - 1];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0] + abs(a[i][p - 1] - a[i - 1][0]), dp[i - 1][1] + abs(a[i][p - 1] - a[i - 1][p - 1]));
        dp[i][1] = min(dp[i - 1][0] + abs(a[i][0] - a[i - 1][0]), dp[i - 1][1] + abs(a[i][0] - a[i - 1][p - 1]));
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]) + s << endl;
}

int main() {
    long long t; cin >> t;
    for (long long i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
