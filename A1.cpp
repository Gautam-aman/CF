#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> freq(201, 0); 
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x >= 0 && x < (int)freq.size()) freq[x]++;
        }
        int mex = 0;
        while (mex < (int)freq.size() && freq[mex] > 0) ++mex;
        cout << mex << '\n';
    }
    return 0;
}
