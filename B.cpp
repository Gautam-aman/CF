#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if(!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        long long bad = (x & y & ~z) | (x & z & ~y) | (y & z & ~x);
        cout << (bad ? "NO\n" : "YES\n");
    }
    return 0;
}
