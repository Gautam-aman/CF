#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

int solve(string s , string match){
    int index = match.size()-1;
    int operations = 0 ;

    int n = s.size();
    for (int i = n-1 ; i >= 0 ;i--){
        if(s[i] == match[index]){
            index--;
            if (index < 0) break;
        }
        else operations++;
    } 

    if(index >= 0) return INT_MAX;
    return operations;

}

void solve() {
   string s;
   cin >> s;
   vector<string> match = {"25" , "00", "50","75"};
   int ans = INT_MAX;
   for(auto it : match){
        ans = min(ans , solve(s , it));
   }

   cout << ans << endl;

}


int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}