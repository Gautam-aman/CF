#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n , k ;
    cin >> n >> k;
    string s ;
    cin >> s;
    unordered_map <char , int> mpp;
    for (auto it : s){
        mpp[it]++;
    }
    int count = 0;
    for(auto it : mpp){
       int value = it.second % 2;
       if (value ==1) count++;
    }
    if ( n - k ==1 ){
        cout << "YES" << endl ;
        return ;
    }
    
    if (count - 1 <= k){
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