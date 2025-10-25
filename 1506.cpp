#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

int lcs(string s1 , string s2){
    int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp( n+1 , vector<int>(m+1,0));
        int maxi = 0;
        vector<int> prev(m+1,0) , curr(m+1 ,0);
        for (int i = 1 ; i<=n ; i++){
            for (int j = 1 ; j <= m ;j++){
                if (s1[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                    maxi = max(maxi ,curr[j]);
                }
                else curr[j] = 0;
            }   
            prev = curr;
        }
        return maxi;
}

void solve() {
    string a , b ;
    cin >> a >> b;
    int n1= a.size();
    int n2 = b.size();
    
    int ans = n1 + n2 - (2 * lcs(a , b));
    cout << ans << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}