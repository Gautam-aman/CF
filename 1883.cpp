#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n , k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i =0 ; i < n ; i++ ) cin >> nums[i];
    int evenCount = 0 ;
    int ans = 1e9;
    for(auto it: nums){
        if (it%2 == 0) evenCount++;
        if (it % k == 0){
            cout << "0" << endl;
            return;
        }
       ans = min(ans, k - (it % k));

    }
    // for case of 4
   if (k == 4){
    if(evenCount >= 2) ans= 0 ;
    else if (evenCount ==1 ) ans = min(ans, 1);
   else  ans = min(ans , 2);
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