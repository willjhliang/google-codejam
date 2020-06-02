#include <bits/stdc++.h>

using namespace std;

string a[100];

void solve(int test) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string st = "";
    for (int i = 0; i < n; i++) {
        if (a[i][0] == '*') continue;
        for (int j = 0; j < min(st.length(), a[i].length()); j++) {
            if (a[i][j] == '*') break;
            if (a[i][j] != st[j]) {
                cout << "Case #" << test << ": *" << endl;
                return;
            }
        }
        string sub = "";
        for (int j = 0; j < a[i].length(); j++) {
            if (a[i][j] == '*') break;
            sub += a[i][j];
        }
        if (sub.length() > st.length()) st = sub;
        a[i] = a[i].substr(sub.length(), a[i].length() - sub.length());
    }
    string en = "";
    for (int i = 0; i < n; i++) {
        int s = a[i].length();
        if (a[i][s - 1] == '*') continue;
        for (int j = 0; j < min(en.length(), a[i].length()); j++) {
            if (a[i][s - 1 - j] == '*') break;
            if (a[i][s - 1 - j] != en[j]) {
                cout << "Case #" << test << ": *" << endl;
                return;
            }
        }
        string sub = "";
        for (int j = a[i].length() - 1; j >= 0; j--) {
            if (a[i][j] == '*') break;
            sub += a[i][j];
        }
        if (sub.length() > en.length()) en = sub;
        a[i] = a[i].substr(0, a[i].length() - sub.length());
    }
    reverse(en.begin(), en.end());
    string ans = st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].length(); j++) {
            if (a[i][j] != '*') ans += a[i][j];
        }
    }
    cout << "Case #" << test << ": " << (ans + en) << endl;
    /* string end = ""; */
    /* for (int i = 0; i < n; i++) { */
    /*     if (a[i].back() == '*') continue; */
    /*     for (int j = 0; j < end.length(); j++) { */
    /*         if ((j + 1) > a[i].length() || a[i][a[i].length() - (j + 1)] == '*') break; */
    /*         if (a[i][a[i].length() - (j + 1)] != end[end.length() - (j + 1)]) { */
    /*             cout << "Case #" << test << ": " << "*" << endl; */
    /*             return; */
    /*         } */
    /*     } */
    /* } */
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
