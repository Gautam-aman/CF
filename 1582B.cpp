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
    vector<ll> nums(n);
   
    for(int i =0 ; i < n ;i++) cin >> nums[i];
   
    int one = 0 ;
    int zero =0 ;
    for(int i = 0 ; i < n ; i++){
        if (nums[i] == 0) zero++;
        if (nums[i] == 1) one++;
    }

   ll ways = one * (1LL << zero);

    cout << ways<< endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}