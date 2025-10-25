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
    for(int i =0 ; i < n-1 ; i++){
        cin >> nums[i];
    }
       int sum = 0;

    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];
    }
    sum *= -1;
    cout << sum << "\n";

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}