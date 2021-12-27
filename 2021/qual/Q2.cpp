
#include <bits/stdc++.h>

using namespace std;

int dp[1010][2];

void solve(int C) {
    int x, y; cin >> x >> y;
    string s; cin >> s;
    int n = s.length();

    dp[0][0] = 0;
    dp[0][1] = 0;
    if (s[0] == 'C') {
        dp[0][1] = 2000000000;
    }
    if (s[0] == 'J') {
        dp[0][0] = 2000000000;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'C') {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
            dp[i][1] = 2000000000;
        } else if (s[i] == 'J') {
            dp[i][0] = 2000000000;
            dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
        } else {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
            dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
        }
    }
    
    cout << "Case #" << C << ": " << min(dp[n][0], dp[n][1]) << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
