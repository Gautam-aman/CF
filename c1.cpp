#include <bits/stdc++.h>
using namespace std;

bool solve(long long n) {
    if (n == 0) return true; // x=1 works
    for (int k = 1; k <= 30; ++k) {
        if ((1LL << (k-1)) > n) break; // length k too long
        bool ok = true;
        if (k % 2 == 1) {
            int mid = k/2;
            if ((n >> mid) & 1) ok = false;
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        cout << (solve(n) ? "YES\n" : "NO\n");
    }
}
