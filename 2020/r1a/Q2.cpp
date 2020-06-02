#include <bits/stdc++.h>

using namespace std;

int a[510][510];
void solve(int test) {
    a[0][0] = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) a[i][j] = 1;
            else a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    int n; cin >> n;
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= i / 2; j++) {
            if (a[i][j] > n) continue;
            // walk to edge
            int ii = i, jj = j;
            int sum = 0;
            while (jj > 0) {
                sum += a[ii][jj];
                ii--; jj--;
            }
            if (sum + (ii + 1) > n) continue;
            int diff = n - (sum + (ii + 1));
            if (diff > ii) continue;
            cout << "Case #" << test << ": " << endl;
            for (int k = 0; k <= i; k++) {
                if (k <= ii) {
                    if (k > 0 && a[k][1] == diff) cout << (k + 1) << " " << 2 << endl;
                    cout << (k + 1) << " " << 1 << endl;
                }
                else cout << (k + 1) << " " << (k - ii + 1) << endl;
            }
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
