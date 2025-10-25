#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

bool isEven(int num){
    return num%2 == 0 ;
}

void solve() {
    int n ;
    cin >> n ;
    vector<int> nums(n);
    for(int i =0 ; i < n ; i++){
        cin >> nums[i];
    }
    int count =0 ;
    for (int i =0 ; i < n-1 ; i++){
        if (isEven(nums[i]) == isEven(nums[i+1])){
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}