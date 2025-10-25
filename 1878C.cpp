#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    long long n,k,x;
    cin >> n >> k >> x;

    
    long long minSum = (k * (k+1))/2;
    long long maxSum = (k * (2 * n -k +1))/2;

    if (x <= maxSum && x >= minSum){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    


}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}