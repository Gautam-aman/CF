#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n , a, b ;
    cin >> n  >> a >> b;
    if (a + b + 2 <= n || ((a == b) && (a == n))){
        cout <<"YES" << endl;
    }
    else {cout<< "NO" << endl;}
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}