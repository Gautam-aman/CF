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
    for(int i =0 ; i <n ; i++ ) cin >> nums[i];
    map<int ,vector<int>> mpp;
    for(int i =0 ; i < n ; i++){
        mpp[nums[i]].push_back(i+1);
    }
    vector<int> ans;
    for(auto &it : mpp){
        if (it.second.size() ==1){
            cout << "-1" << endl;
            return;
        }
        rotate(it.second.begin() , it.second.begin() +1 , it.second.end());
        for(auto ad : it.second){
            ans.push_back(ad);
        }
    }
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
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