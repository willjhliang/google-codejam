
#include <bits/stdc++.h>

using namespace std;


void solve(int C) {
    cout << "Case #" << C << ": ";

    long long y; cin >> y;
    int n = trunc(log10(y)) + 1;
    long long best = 1e18;

    long long foo = 1;
    for (int l = 1; l < n / 2; l++) {
        long long bar = pow(10, l);
        long long m = 0;
        if (n % l == 0) {
            for (int i = 0; i < n; i += l) {
                m++;
                long long c = (n % foo) / foo;
                m = max(c, m);
                foo *= bar;
            }
            long long r = 0;
            // for (int i = 0; i < n; i += l) { REVERSE
            //     foo /= bar;
            //     r += foo * m;
            //     m--;
            // }
            best = min(best, r);
        } else if ((n - l - 1) % l == 0) {
            m = pow(10, l + 1);
            // FINISH
        }
    }

}

int main() {
    freopen("../../test.in", "r", stdin);
    freopen("../../test.out", "w", stdout);

    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
