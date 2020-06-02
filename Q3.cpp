#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
    int n, d; cin >> n >> d;
    if (d > 3) return;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        long long a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    long long rep2 = v[v.size() - 1] + 1;
    bool rep3 = false;
    bool doub = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] == v[j]) rep2 = min(rep2, v[i]);
            if (v[i] * 2 == v[j] || v[j] * 2 == v[i]) doub = true;
            for (int k = j + 1; k < n; k++) {
                if (v[i] == v[j] && v[j] == v[k]) 
                    rep3 = true;
            }
        }
    }
    if (d == 2) cout << "Case #" << test << ": " << ((rep2 != v[v.size() - 1] + 1 )? 0 : 1) << endl;
    else {
        int ans = 2;
        if (rep3) ans = 0;
        if (rep2 < v[v.size() - 1]) ans = 1;
        if (doub) ans = 1;

        cout << "Case #" << test << ": " << ans << endl;
    }
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
