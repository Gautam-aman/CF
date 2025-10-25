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
    string s ;
    cin >> s;
    set<char> st;
    vector<int> front , back;
    for(int i =0 ;i < n ; i++){
        st.insert(s[i]);
        front.push_back(st.size());
    }
    st.clear();
    for(int i = n-1 ; i >= 0 ; i--){
        st.insert(s[i]);
        back.push_back(st.size());
    }
    reverse(back.begin() , back.end());
    int ans = 0 ;
    for(int i =0 ; i< n -1; i++){
        ans = max(ans , front[i]+back[i+1]);
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