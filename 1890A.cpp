#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> freq;
    
    for (int &x : a) {
        cin >> x;
        freq[x]++;
    }

    if (freq.size() == 1) { 
        cout << "Yes\n";
        return;
    }
    
    if (freq.size() > 2) { 
        cout << "No\n";
        return;
    }

    auto it = freq.begin();
    int val1 = it->first, cnt1 = it->second;
    it++;
    int val2 = it->first, cnt2 = it->second;

    if (n % 2 == 0) {
        cout << ((cnt1 == n / 2 && cnt2 == n / 2) ? "Yes\n" : "No\n");
    } else {
        cout << ((cnt1 == n / 2 + 1 && cnt2 == n / 2) || (cnt1 == n / 2 && cnt2 == n / 2 + 1) ? "Yes\n" : "No\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
