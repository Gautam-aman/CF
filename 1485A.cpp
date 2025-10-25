#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    ll a , b;
    cin >> a >> b;
    
    long long ans = 1e9;
    for(int add = 0 ; add <= 32 ; add++){
        
        long long operations = add ;
        long long   sum = b + add;
        if (sum == 1) continue; // never reach the condtion
        long long value = a;
        while (value > 0){
            value /= sum;
            operations++;
        }
        if (value == 0) ans = min(ans , operations);
        
        
    }

    cout << ans << endl;
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}