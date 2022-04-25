
#include <bits/stdc++.h>

using namespace std;

void solve(int C) {
    cout << "Case #" << C << ": ";

    string s; cin >> s;
    string ret = "";
    for (int i = 0; i < s.length(); i++) {
        ret.append(s.substr(i, 1));
        bool hi = false;
        for (int j = i + 1; j < s.length(); j++) {
            if (s[j] > s[i]) {
                hi = true;
                break;
            } else if (s[j] < s[i]) {
                break;
            }
        }
        if (hi) {
            ret.append(s.substr(i, 1));
        }
    }
    cout << ret << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
