#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    string cur = x;
    int ops = 0;

    // Grow until at least length of s
    while (cur.size() < s.size()) {
        cur += x;
        ops++;
    }

    // Check up to 2 more times
    for (int extra = 0; extra <= 2; extra++) {
        if (cur.find(s) != string::npos) {
            cout << (ops + extra) << "\n";
            return;
        }
        cur += x;
    }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
