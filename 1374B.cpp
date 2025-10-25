#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    ll n ;
    cin >> n;
    if (n == 1){
        cout << "0" << endl;
        return;
    }
    int count= 0;
    while (true){
        if (n == 1) break;
        if(n % 6 == 0){
            n = n / 6;
            count++;
        }
        else if(n % 3 == 0){
            n = n*2 ;
            count++;
        }
        else{
            count = -1;
            break;
        }
    }

    cout << count << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}