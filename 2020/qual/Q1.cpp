
#include <bits/stdc++.h>

using namespace std;

int a[110][110];
int b[110];

void solve(int test) {
    int n; cin >> n;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[j][i];
            if (i == j) k += a[j][i];
        }
    }
    int r = 0, c = 0;
    for (int i = 0; i < n; i++) {
        memset(b, 0, sizeof b);
        for (int j = 0; j < n; j++) {
            if (b[a[j][i]]) {
                r++;
                break;
            }
            b[a[j][i]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        memset(b, 0, sizeof b);
        for (int j = 0; j < n; j++) {
            if (b[a[i][j]]) {
                c++;
                break;
            }
            b[a[i][j]] = 1;
        }
    }
    cout << "Case #" << test << ": " << k << " " << r << " " << c << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
