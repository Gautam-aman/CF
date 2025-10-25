#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        nums[i].resize(m);
        for (int j = 0; j < m; j++) cin >> nums[i][j];
        sort(nums[i].begin(), nums[i].end()); 
    }

    int firstMin = INT_MAX;
    int secondMin = INT_MAX;
    long long total = 0;

    for (int i = 0; i < n; i++) {
       
        if (nums[i].size() > 1)
            total += nums[i][1];
        else
            total += nums[i][0];

        firstMin = min(firstMin, nums[i][0]);
        if (nums[i].size() > 1)
            secondMin = min(secondMin, nums[i][1]);
    }

    long long ans = total - secondMin + firstMin;
    cout << ans << "\n";
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
