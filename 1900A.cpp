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
    string s;
    cin >> s;
    if (s.find("...") != string::npos){
        cout << "2\n";
    }
    else{
        int count = 0 ;
        for (auto it : s){
            if (it == '.') count++;
        }
        cout << count <<"\n";
    }
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}