#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
using ll = long long;

void solve() {
    ll RO, X, D, n;
    cin >> RO >> X >> D >> n;
    string s;
    cin >> s;

    vector<vector<ll>> mini(n + 1, vector<ll>(n + 1, 1e9 + 7)); 
    vector<vector<ll>> maxi(n + 1, vector<ll>(n + 1, -1));       

    mini[0][0] = RO;
    maxi[0][0] = RO;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (mini[i][j] > maxi[i][j]) continue;

            ll nextMin = mini[i][j];
            ll nextMax = maxi[i][j];

            if (s[i] == '1') {
                // rated always 
                ll newmini = max(0LL, nextMin - D);
                ll newmax = nextMax + D;
                mini[i + 1][j + 1] = min(mini[i + 1][j + 1], newmini);
                maxi[i + 1][j + 1] = max(maxi[i + 1][j + 1], newmax);
            } else {
                if (nextMin < X) {
                    ll newmini = max(0LL, nextMin - D);
                    ll newmax = min(nextMax, X - 1) + D;
                    mini[i + 1][j + 1] = min(mini[i + 1][j + 1], newmini);
                    maxi[i + 1][j + 1] = max(maxi[i + 1][j + 1], newmax);
                }

                if (nextMax >= X) {
                    ll newmini = max(X, nextMin);
                    ll newmax = nextMax; 
                    mini[i + 1][j] = min(mini[i + 1][j], newmini);
                    maxi[i + 1][j] = max(maxi[i + 1][j], newmax);
                }
            }
        }
    }

    int maxRounds = 0;
    for (int i = n; i >= 0; i--) {
        if (mini[n][i] <= maxi[n][i]) {
            maxRounds = i;
            break;
        }
    }

    cout << maxRounds << endl;
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}