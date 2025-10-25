#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

int findxor(long long n){
    if(n % 4 == 0) return n;
    else if (n % 4 ==1) return 1;
    else if (n % 4 == 2) return n+1;
    else return 0;
}

void solve() {
    long long a , b ;
    cin >> a >> b;

    long long xorofall = findxor(a-1);
    if (xorofall == b){
        cout << a << endl;
    }
    else if( (xorofall ^ b) != a){
        cout << a +1 << endl;
    }
    else cout << a + 2 << endl;


}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}