#include<bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

void solve(){
    int n ; 
    int x;
    cin >> n;
    cin >> x;
    vector<int> nums(n);
    for (int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }

    int maxi = nums[0]-0;
    for (int i = 1 ;i < n ;i++){
        maxi = max(maxi , nums[i]-nums[i-1]);
    }
    int roundtrip = 2 * (x - nums[n-1]);
    maxi = max(maxi , roundtrip);

    cout <<  maxi  << "\n";

}

int main(){

    fastio

    int T; 
    cin>>T;
    while (T--) solve();
    
return 0;
}