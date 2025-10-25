#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0 ; i < n ; i++) cin >> nums[i];
    map<int, int> mpp;
    for(auto it : nums) mpp[it]++;
    int max_freq = 0;
    for (auto it : mpp) {
        max_freq = max(max_freq , it.second);
    }

    int operations = 0 ;

    while(max_freq < n){
        operations++;
        if(max_freq * 2 <= n){
            operations += max_freq;
            max_freq *= 2;
        }
        else{
            operations += n - max_freq;
            max_freq = n;
        }
    }

    cout << operations << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}