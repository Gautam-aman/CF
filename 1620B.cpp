#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

  
    vector<pii> temp;
    for(int i = 0; i < n; i++) temp.push_back({nums[i], i+1});


    sort(temp.rbegin(), temp.rend());

    vector<int> ans(n+1, 0); 
    ll totaldist = 0;
    int left = -1, right = 1;

    // Alternate placement left/right
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            ans[temp[i].second] = right;
            totaldist += 2LL * abs(right) * temp[i].first;
            right++;
        } else {
            ans[temp[i].second] = left;
            totaldist += 2LL * abs(left) * temp[i].first;
            left--;
        }
    }

    cout << totaldist << "\n";
    for(int i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    fastio;
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
