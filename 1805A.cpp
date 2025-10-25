#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int X = 0; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        X ^= a[i];
    }

    if(n % 2 == 1) {
       
        cout << X << "\n";
    } else {
        // n is even → XOR must be 0
        if(X == 0) cout << 0 << "\n";
        else cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
