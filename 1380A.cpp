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
    for(int i = 0 ; i < n ; i++) cin >> nums[i];
    int index = -1;
    for (int i =1 ; i < n-1 ; i++){
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
            index = i;
            break;
        }
    }
    if (index == -1) cout << "NO"<< endl;
    else {
        cout << "YES" << endl;
        cout << index << " " << index+1 << " " << index+2 << endl;
    }
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}