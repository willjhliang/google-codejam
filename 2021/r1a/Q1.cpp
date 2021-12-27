
#include <bits/stdc++.h>

using namespace std;

long long a[110];

void solve(long long C) {
    long long n; cin >> n;
    string back; cin >> back;
    int res = 0;
    for (int i = 1; i < n; i++) {
        string cur; cin >> cur;
        if (cur.length() > back.length()) {
            back = cur;
            continue;
        }

        int diff = back.length() - cur.length();
        string sub = back.substr(0, cur.length());
        if (stoi(cur) > stoi(sub)) {
            back = cur + string(diff, '0');
            res += diff;
            continue;
        } else if (stoi(cur) < stoi(sub)) {
            back = cur + string(diff + 1, '0');
            res += diff + 1;
            continue;
        } else {
            int j = back.length() - 1;
            while (j >= 0) {
                if (back[j] != '9') {
                    back[j] = char(back[j] + 1);
                    break;
                }
                else {
                    back[j] = '0';
                    j--;
                }
            }
            if (back[0] == '0')
                back = "1" + back;
            if (back.substr(0, cur.length()) == cur) {
                res += (back.length() - cur.length());
                continue;
            } else {
                back = cur + string(diff + 1, '0');
                res += diff + 1;
                continue;
            }
        }
    }
    cout << "Case #" << C << ": " << res << endl;
}

int main() {
    long long t; cin >> t;
    for (long long i = 0; i < t; i++)
        solve(i + 1);
    return 0;
}
