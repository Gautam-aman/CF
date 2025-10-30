#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
   int n;
    cin >> n;
    vector<long long> a(n);
    bool hasEven = false, hasOdd = false;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) hasEven = true;
        else hasOdd = true;
    }

    if (hasEven && hasOdd) {
        vector<long long> b = a;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << b[i];
        }
        cout << '\n';
    } else {
       
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}