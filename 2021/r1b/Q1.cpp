
#include <bits/stdc++.h>

using namespace std;


void solve(int C) {
    cout << "Case #" << C << ": ";

    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    long long tnano = 12 * 60 * 60 * 1e9;
    long long hnano = 60 * 60 * 1e9;
    long long mnano = 60 * 1e9;
    long long snano = 1e9;
    do {
        long long ah = a[0];
        long long am = a[1];
        long long as = a[2];
        long long numer;
        long long denom;
        for (int h = 0; h < 12; h++) {
            long long d = ah - h * hnano;
            long long ah_shift = ah - d;
            long long am_shift = (am - d + tnano) % tnano;

            if (am_shift % 11 != 0 || am_shift < 0) {
                continue;
            }
            long long p = am_shift / 11;
            long long t = h * hnano + p;
            long long rot = ah - t;

            int m = ((am - rot + tnano) % tnano) / 12 / mnano;
            int s = ((as - rot + tnano) % tnano) / 720 /  snano;
            int n = (((as - rot + tnano) % tnano) / 720 - s * snano);
            if (h == (int)(t / hnano) && m == (int)((t / mnano) % 60) && s == (int)((t / snano) % 60) && n == (int)(t % (long long)1e9)) {
                if (m >= 0 && m < 60 && s >= 0 && s < 60 && n >= 0 && n < 1e9) {
                    cout << h << " " << m << " " << s << " " << n << endl;
                    return;
                }
            }
        }
    } while (next_permutation(a, a + 3));
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
