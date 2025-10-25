#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    long long a , b ;
    cin >> a >> b;
    if (a == b){
        cout << '0' << " " << '0' << endl;
        return;
    }

    long long big ;
    long long small;
    if (a>b){
        big = a ;
        small = b;
    }
    else{
        big = b ;
        small = a;
    }
    long long hcf = big - small;
    long long diff = small % hcf;
    long long steps = min(diff , hcf-diff);

    cout << hcf << " " << steps << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}