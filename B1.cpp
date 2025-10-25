#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

    
        vector<pair<ll,ll>> vec;
        ll dp_prev = 0; // dp[0] = 0
        for (int i = 0; i < n; ++i) {
            vector<pair<ll,ll>> newv;
           
            newv.emplace_back(a[i], dp_prev);

           
            for (auto &p : vec) {
                ll m = p.first;
                ll best = p.second;
                ll nm = min(m, a[i]);
                if (newv.back().first == nm) {
                   
                    newv.back().second = min(newv.back().second, best);
                } else {
                    newv.emplace_back(nm, best);
                }
            }

            
            ll dp_cur = INF;
            for (auto &p : newv) {
                ll m = p.first;
                ll best = p.second;
                // ceil division
                ll cost = (a[i] + m - 1) / m;
                dp_cur = min(dp_cur, best + cost);
            }

            dp_prev = dp_cur;
            vec.swap(newv);
        }

        cout << dp_prev << '\n';
    }
    return 0;
}
