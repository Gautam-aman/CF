#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

void solve() {
    int x, k;
    cin >> x >> k;

    // if (k == 1) {
    //     cout << "NO\n";
    //     return;
    // }

    if (x % k != 0) {
        cout << 1 << "\n" << x << "\n";
    } else {
        cout << 2 << "\n" << x - 1 << " " << 1 << "\n";
    }
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
