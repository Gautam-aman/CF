#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n ;
    cin >> n ;
    vector<int> nums(n);
    for (int i =0 ; i < n ; i++) cin >> nums[i];

    //sort(nums.begin() , nums.end());
    map<int ,int> mpp;
    for (auto it : nums) mpp[it]++;
    int count = 0 ;
    for (auto it : mpp) {
        if (it.second == 1) count++;
    }
    if (count == n) {
        cout << "0" << endl;
        return;
    }

    if (n == 3){
        if (nums[n-1] >= nums[n-2] + nums[n-3]) {
            cout << "0" << endl;
            return;
        }
        else {
            int ans = accumulate(nums.begin() , nums.end() , 0);
            cout << ans << endl;
            return;
        }
    }

    int total = 0 ;
    for (auto it : mpp){
        if (it.second ==2 ) total += it.first;
    }

    priority_queue<int> pq;
    int len = 0;
    for(auto it : mpp){
        if (it.second == 1){
            pq.push(it.first);
            len++;
        }
        if (len == count) break;
    }
    total += pq.top();
    pq.pop();
    total += pq.top();
    cout << total << endl;

   
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}