#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n , k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i= 0 ;i < n ;i++){
        cin >> nums[i];
    }
    bool flag = false;
    for(int i = 0; i < n ; i++){
        if (nums[i] == k){
            flag = true;
            break;
        }
    }

    if (flag){
        cout << "YES\n" ;
    }
    else {
        cout << "NO\n";
    }

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}