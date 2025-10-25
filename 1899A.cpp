#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n ;
    cin >> n;
    if (n%3 == 0 ){
        cout << "Second\n";
    }
    else {
        cout << "First\n";
    }
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}