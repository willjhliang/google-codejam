#include <bits/stdc++.h>

using namespace std;

/* ifstream fin("test.in"); */
/* ofstream fout("test.out"); */
int a[30];
int b[30];
bool start[30];
bool seen[30];

void solve(int test) {
    for (int i = 0; i < 26; i++) a[i] = 2000000000;
    int u; cin >> u;
    for (int i = 0; i < 10000; i++) {
        int q; cin >> q;
        string qs = to_string(q);
        string s; cin >> s;
        /* fout << s << endl; */
        for (int j = 0; j < s.length(); j++) {
            seen[s[j] - 'A'] = true;
            if (j == 0) {
                start[s[j] - 'A'] = true;
                if (q != -1 && qs.length() == s.length())
                    a[s[j] - 'A'] = min(a[s[j] - 'A'], int(qs[j]) - '0');
            } else {
                if (q != -1 && qs.length() == s.length())
                    b[s[j] - 'A'] = min(b[s[j] - 'A'], int(qs[j] - '0');
            }
            /* fout << s[j] - 'A' << " " << a[s[j] - 'A'] << " " << int(qs[j]) - '0' << endl; */
        }
    }
    string ans = "----------";
    for (int i = 0; i < 26; i++) {
        if (a[i] == 2000000000) continue;
        ans[a[i]] = char(i + 'A');
        seen[i] = false;
    }
    for (int i = 0; i < 26; i++) {
        if (seen[i] && !start[i]) {
            ans[0] = char(i + 'A');
            seen[i] = false;
        }
    }
    string t = "";
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] != '-') t += ans[i];
    }
    ans = t;
    for (int i = 0; i < 10; i++) {
        if (ans[i] == '-') {
            for (int j = 0; j < 26; j++) {
                if (seen[j]) {
                    ans[i] = char(j + 'A');
                    seen[j] = false;
                    break;
                }
            }
        }
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
