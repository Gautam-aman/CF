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
    vector<int> nums(n , 0);
    for (int i =0 ;i < n ; i++){
        cin >> nums[i];
    }

    vector<int> ans;
    for(int i = 0;i < n ; i++){
        if (!ans.empty() && ans.back() > nums[i]){
            ans.push_back(1);
        }
        ans.push_back(nums[i]);
    }

    int len = ans.size();
    cout << len << "\n";
    for (int i = 0 ; i < len ; i++){
        cout << ans[i] << " " ;
    }

    cout << "\n";

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}