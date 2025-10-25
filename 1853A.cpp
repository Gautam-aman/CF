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
    for (int i= 0 ; i < n ; i++){
        cin >> nums[i];
    }
    int mini = 1e9;
    for(int i = 1 ; i < n ;i ++){
        if (nums[i] < nums[i-1]){
            cout << "0" << endl;
            return;
        }
        mini = min(mini , nums[i]-nums[i-1]);
    }

    int totalmoves = (mini /2 )+1;
    cout << totalmoves << endl ;


}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}