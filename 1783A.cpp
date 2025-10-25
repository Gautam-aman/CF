#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n;
    cin >> n ;
    vector<int> nums(n);
    for(int i =0 ; i < n ; i++){
        cin >> nums[i];
    }
    sort(nums.begin() , nums.end());
    if (nums[0] == nums[n-1]){
        cout << "NO" << endl;
        return;
    }
    cout <<"YES"<< endl;
    cout << nums[n-1] << " ";
    for(int i = 0 ; i < n-1 ;i++){
        cout << nums[i] << " ";
    }
    cout << endl ;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}