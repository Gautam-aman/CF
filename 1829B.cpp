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
    vector<int>nums(n);
    for (int i = 0 ;i < n ; i++){
        cin >> nums[i];
    }

    int maxLen = 0 ;
    int right = 0 ;
    while (right < n ){
        if(nums[right] == 0){
            int count=  1;
            int temp = right+1;
            while (temp < n && nums[temp] == 0){
                temp++;
                count++;
            }
            maxLen = max(maxLen , temp - right);
            right = temp;
        }
        else right++;
    }
    
    cout << maxLen << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}