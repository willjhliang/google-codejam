
#include <iostream>

using namespace std;

void solve(int C) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    for (int i = 0; i < 2; i++) {
        int e, f, g, h;
        cin >> e >> f >> g >> h;
        a = min(a, e);
        b = min(b, f);
        c = min(c, g);
        d = min(d, h);
    }

    cout << "Case #" << C << ": ";

    if (a + b + c + d < 1e6) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int res[] = {0, 0, 0, 0};
        int s = 0;
        if (s < 1e6) {
            res[0] = a;
            s += a;
            if (s > 1e6) {
                res[0] = 1e6;
            }
        }
        if (s < 1e6) {
            res[1] = b;
            s += b;
            if (s > 1e6) {
                res[1] = 1e6 - res[0];
            }
        }
        if (s < 1e6) {
            res[2] = c;
            s += c;
            if (s > 1e6) {
                res[2] = 1e6 - res[0] - res[1];
            }
        }
        if (s < 1e6) {
            res[3] = d;
            s += d;
            if (s > 1e6) {
                res[3] = 1e6 - res[0] - res[1] - res[2];
            }
        }
        cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << endl;
    }
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
