#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

// 4
// 4
// 7
// 24
// 548

void solve() {
    long long n ;
    cin >> n;
    if (n % 2 == 1 || n < 4) {
        cout << "-1" << endl;
        return;
    }
    
    long long maxi = n/4;
    long long mini = ceil(n/6.0);

   if (maxi ==0 || mini == 0){
       long long value = max(mini , maxi);
       cout << value << " " << value << endl;
   }
   else {
       cout << mini << " " << maxi << endl;
   }
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}