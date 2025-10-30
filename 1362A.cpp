#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    long long a , b ;
    cin >> a>> b;
    
    long long ra = a , rb = b;
    while (ra % 2 ==0) ra/=2;
    while(rb % 2 == 0) rb/=2;
    if(ra != rb){
        cout << "-1" << endl;
    }
    else{
        a /= ra;
        b /= rb;
        a = log2(a);
        b = log2(b);
        long long ans = ceil(abs(a-b) / 3.0);
        cout << ans << endl ;
    }
    

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}