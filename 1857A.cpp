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
    for (int i =0 ; i< n ;i++){
        cin >> nums[i];
    }
    int sum = accumulate(nums.begin() , nums.end() , 0);
    if (sum % 2 ==0) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}