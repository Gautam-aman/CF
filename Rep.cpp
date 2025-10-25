#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;




int main() {
    fastio;

    string s;
    cin >> s;
    char ch = s[0];
    int count =1;
    int maxlen = 0;
    for(int i = 1 ; i < s.size() ; i++){
        if (s[i] == ch){
            count++;
        }
        else{
            maxlen = max(maxlen , count);
            count = 1;
            ch = s[i];
        }
    }

    maxlen = max(maxlen , count);
    
    cout << maxlen << endl;

    return 0;
}