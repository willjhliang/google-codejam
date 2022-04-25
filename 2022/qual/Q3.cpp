
#include <iostream>

using namespace std;

void solve(int C) {
    int a[100010];
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int j = 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= j) {
            res += 1;
            j++;
        }
    }

    cout << "Case #" << C << ": " << res << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
