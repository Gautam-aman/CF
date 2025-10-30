#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(b.begin(), b.end());
    for (int i = 1; i < n; i++) {
        if (b[i] == b[i - 1]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
