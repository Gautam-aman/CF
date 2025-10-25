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
    vector<int> nums(n);
    for (int i = 0 ; i< n ; i++) cin >> nums[i];
    
    for(int i = 0 ; i < n-1 ; i++){
        if (nums[i] == 1) nums[i]++;
    }

    for(int i = 1; i < n ; i++){
        if (nums[i] % nums[i-1] ==0) nums[i]++;
    }

    for(int i =0 ;  i < n ; i++){
        cout << nums[i] << " ";
    }

    cout << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}