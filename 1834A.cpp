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
    for(int i =0 ; i < n ; i++){
        cin >> nums[i];
    }

    int negatives = 0 ;
    int sum =0 ;
    for (int i = 0 ;i < n ; i++){
        if(nums[i] < 0) negatives++;
        sum += nums[i]; 
    }
    int changes = 0 ;
    if (negatives % 2 == 1){
        changes++;
        sum += 2;
    }

    if (sum >= 0 ){
        cout << changes << endl;
        return ;
    }

    while (true){
        sum += 4;
        changes += 2;
        if(sum >= 0) break;
    }

    cout << changes << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}