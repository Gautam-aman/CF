#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll g = gcd(2LL, k);
    if (n % g == 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
