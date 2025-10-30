#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;




int main() {
    fastio;
    int n ;
    cin >> n;
    string s;
    cin >> s;
   // int n = s.size();
    
   int prev = s[0]-'a';
   int prevIndex = 0;
   bool possible = false;
   for(int i = 1 ; i < n ; i++){
    char ch = s[i]-'a';
    if (prev > ch){
        cout <<"YES" << endl;
        cout << prevIndex+1 << " " << i+1 << endl;
        possible= true;
        break;
    }
    if (ch > prev){
        prev = ch;
        prevIndex = i;
    }
   }

   if (!possible) cout << "NO" << endl;
    

    return 0;
}