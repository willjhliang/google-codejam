
#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
    string s; cin >> s;
    string ans = "";
    int dep = 0;
    for (int i = 0; i < s.size(); i++) {
        while (dep < int(s[i] - '0')) {
            ans += "(";
            dep++;
        }
        while (dep > int(s[i] - '0')){
            ans += ")";
            dep--;
        }
        ans += s[i];
    }
    while (dep > 0) {
        ans += ")";
        dep--;
    }
    cout << "Case #" << test << ": " << ans << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
