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
    for (int i = 0 ; i < n ;i++) cin >> nums[i];
    int ans =0;
    for (int i = n-2 ; i >= 0 ; i--){
        while (nums[i] >= nums[i+1]){
            ans ++;
            nums[i] /= 2;
            if (nums[i] == 0 ) break;
        }
        if (nums[i] == 0 && nums[i+1] == 0) {
            cout << "-1" << endl;
            return;
        }
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