#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int a , b,c ,d;
    cin >> a >>b >> c>> d;
    ll diag = d - b;
    ll xmov = diag + a - c;
    if(diag >= 0 && xmov >= 0){
        cout << diag + xmov << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}