#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n ;
    cin >> n;
    string s ;
    cin >> s ;
    int count = 0 ;
    int open = 0;
    for(auto it : s){
        if(it =='(') open++;
        else {
            if (open > 0) open--;
            else count++;
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