#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve(){
    int n; 
    cin >> n;
    
    map<int,int> freq , first , last;
    int maxi = 0;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
        if(!first.count(x)) first[x] = i;
        last[x] = i;
        maxi = max(maxi , x);
    }
    
    vi dp(maxi + 1 , 0);
    
    for(int num = 1; num <= maxi; num++){
        if(!freq.count(num)){
            dp[num] = dp[num - 1];
            continue;
        }
        
        int nottake = dp[num - 1];
        int take = freq[num];
        int prev = num - 1;
        
        if(prev > 0 && freq.count(prev)){
            bool ok = (first[prev] >= last[num]);
            if(ok) take += dp[prev];
            else take += (num >= 2 ? dp[num - 2] : 0);
        }
        else take += dp[prev];
        
        dp[num] = max(nottake , take);
    }
    
    cout << n - dp[maxi] << '\n';
}

int main(){
    fastio
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}
