
#include <bits/stdc++.h>

using namespace std;

int f;
vector<int> v[10][10];
int ch[5] = {'A', 'B', 'C', 'D', 'E'};
int ct[5] = {120, 24, 6, 2, 1};
bool got[5];

int b[5];

bool cont = true;

void solve(int test) {
    string ans = "";
    for (int i = 0; i < 5; i ++) {
        got[i] = 0;
        b[i] = 0;
        for (int j = 0; j < 5; j++)
            v[j][i].clear();
    }
    for (int i = 0; i < 119; i++) {
        v[0][0].push_back(i * 5 + 1);
    }
    int cur = 0;
    for (int i = 1; i < 5; i++) {
        for (int j : v[cur][i - 1]) {
            cout << j << endl;
            char c; cin >> c;
            v[c - 'A'][i].push_back(j + 1);
        }
        for (int j = 0; j < 5; j++) {
            if (v[j][i].size() != ct[i]) {
                if (got[j]) continue;
                cur = j;
                ans += ch[j];
                got[j] = true;
            }
        }
    }
    for (int i = 0; i < 5; i++)
        if (!got[i]) ans += ch[i];
    cout << ans << endl;
    char c; cin >> c;
    if (c == 'N') cont = false;
}

int main() {
    int t; cin >> t >> f;
    for (int i = 0; i < t; i++) {
        if (cont == false) break;
        solve(i + 1);
    }
    return 0;
}
