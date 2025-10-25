#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    string s ;
    cin >> s; 
    
    int n = s.size();
    int first = 0 ;
    int end = n-1;
    if (s[first] == s[end]){
        cout << s << endl;
    }
    else{
        if(s[first] == 'a') s[first] = 'b';
        else s[first] = 'a';
        
        cout << s << endl;
    }

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}