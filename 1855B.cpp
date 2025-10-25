#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Safe LCM computation (prevents overflow by capping at 1e18)
ll safe_lcm(ll a, ll b) {
    ll g = std::gcd(a, b);
    if (a > LLONG_MAX / (b / g)) return LLONG_MAX; // avoid overflow
    return a / g * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute all possible LCM(1..k) values until exceeding 1e18
    vector<ll> lcms = {1};
    for (int i = 2; ; i++) {
        ll nxt = safe_lcm(lcms.back(), i);
        if (nxt > (ll)1e18) break;
        lcms.push_back(nxt);
    }

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int ans = 1;
        for (int i = 1; i < (int)lcms.size(); i++) {
            if (n % lcms[i] == 0) ans = i + 1;
            else break;
        }
        cout << ans << "\n";
    }
    return 0;
}
