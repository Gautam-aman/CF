#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    string s , target;
    cin >> s >> target;

    unordered_map<char , int> mpp;
    for (auto it : target) mpp[it]++;
    for(int i = s.size()-1 ; i >= 0 ; i--){
        if(mpp.count(s[i]) > 0 && mpp[s[i]] > 0){
            mpp[s[i]]--;
        }
        else{
            s[i] = '.';
        }
    }
    string key = "";
    for(int i = 0; i < s.size() ; i++){
        if(s[i] != '.') key+= s[i];
    }
    if (key == target){
        cout << "YES" << endl;
    }
    else cout << "NO"<< endl;
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}