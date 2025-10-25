#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n , k ;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<int> pre(n+1 , 0);
    for(int i = 0 ; i < n ; i++){
        pre[i+1] = pre[i] + (s[i] == 'W');
    }
    int count = 1e9;
    for(int i = 0 ; i <= n-k ; i++){
        int whites = pre[i+k]- pre[i];
        count = min(count , whites);
    }
    
    cout << count << endl;
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}