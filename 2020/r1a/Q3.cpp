#include <bits/stdc++.h>

using namespace std;

long long a[1010][1010];
long long t[1010][1010];
long long nei[1010][1010][4];
long long tnei[1010][1010][4];

long long dx[] = {0, 1, 0, -1};
long long dy[] = {-1, 0, 1, 0};

void solve(long long test) {
    long long r, c; cin >> r >> c;
    for (long long i = 0; i < r; i++) {
        for (long long j = 0; j < c; j++) {
            cin >> t[j][i];
            for (long long k = 0; k < 4; k++) {
                if (j + dx[k] >= 0 && j + dx[k] < c && i + dy[k] >= 0 && i + dy[k] < r) tnei[j][i][k] = 1;
                else tnei[j][i][k] = -1;
            }
        }
    }
    long long s = 1;
    long long ans = 0;
    while (s > 0) {
        for (long long i = 0; i < c; i++) {
            for (long long j = 0; j < r; j++) {
                a[i][j] = t[i][j];
                for (long long k = 0; k < 4; k++)
                    nei[i][j][k] = tnei[i][j][k];
            }
        }
        s = 0;
        for (long long i = 0; i < c; i++) {
            for (long long j = 0; j < r; j++) {
                if (a[i][j] == 0) continue;
                ans += a[i][j];
                long double avg = 0;
                long long ct = 0;
                for (long long k = 0; k < 4; k++) {
                    if (nei[i][j][k] == -1) continue;
                    avg += a[i + dx[k] * nei[i][j][k]][j + dy[k] * nei[i][j][k]];
                    ct++;
                }
                if (ct == 0) continue;
                if (a[i][j] < (avg / ct)){
                    t[i][j] = 0;
                    s++;
                    for (long long k = 0; k < 4; k++) {
                        long long l = nei[i][j][k];
                        if (l == -1) continue;
                        if (nei[i][j][(k + 2) % 4] == -1)
                            tnei[i + dx[k] * l][j + dy[k] * l][(k + 2) % 4] = -1;
                        else
                            tnei[i + dx[k] * l][j + dy[k] * l][(k + 2) % 4] = l + nei[i][j][(k + 2) % 4];
                    }
                }
            }
        }
    }
    cout << "Case #" << test << ": " << ans << endl;
}

int main() {
    long long t; cin >> t;
    for (long long i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
