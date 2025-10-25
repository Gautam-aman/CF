#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    long long a , b ,n ;
    cin >> a >> b >> n ;
    vector<long long> nums(n);
    for (int i = 0 ; i < n; i++){
        cin >> nums[i];
    }

    long long total_time = b;
    if (total_time == 0){
        cout << "0" << endl;
        return;
    }

    for (auto it : nums){
        if (it < a){
            total_time += it;
        }
        else{
            total_time += a-1;
        }
    }

    cout << total_time << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}