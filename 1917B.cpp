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
    string s ;
    cin >> s; 
    vector<int> distinct(n , 0);
    int count = 0 ;
    unordered_map<char , int> mpp;
    for(int i = 0 ; i < n ;i++){
        mpp[s[i]]++;
        if(mpp[s[i]] == 1) count++;
        distinct[i] = count;
    }

    int ans =accumulate(distinct.begin() , distinct.end(),0);
    cout << ans << endl; 
    

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}