
#include <bits/stdc++.h>

using namespace std;

long long cards[500];

bool valid(long long targ) {
    long long cur = targ;
    long long sum = 0;
    for (int p = 0; p <= 499; p++) {
        if (cards[p] == 0)
            continue;

        long long i = 0;
        while (i < cards[p] && cur % p == 0) {
            cur = cur / p;
            i++;
        }
        if (i > cards[p] && cur % p == 0) {
            return false;
        }
        sum += (cards[p] - i) * p;
    }
    return cur == 1 && targ == sum;
}

void solve(int C) {
    memset(cards, 0, sizeof cards);

    int m; cin >> m;
    long long s = 0;
    for (int i = 0; i < m; i++) {
        long long p, n; cin >> p >> n;
        cards[p] = n;
        s += n * p;
    }

    for (int i = 0; i <= 60 * 499; i++) {
        long long targ = s - i;
        if (targ <= 0) {
            break;
        }
        if (valid(targ)) {
            cout << "Case #" << C << ": " << targ << endl;;
            return;
        }
    }
    cout << "Case #" << C << ": " << 0 << endl;;
}

int main() {
    freopen("../../test.in", "r", stdin);
    freopen("../../test.out", "w", stdout);

    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
