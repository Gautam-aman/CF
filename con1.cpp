#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) {
        int n, k; 
        cin >> n >> k;
        string s; 
        cin >> s;

        int ans = 0;
        int lastOne = -k; 
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (i - lastOne >= k) { 
                    ans++;           
                }
                lastOne = i;       
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
