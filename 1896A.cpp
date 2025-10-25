#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using vi = vector<int>;

bool isSorted(const vi& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i-1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vi nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 1; i < n-1; i++) {
            if (nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
                swap(nums[i], nums[i+1]);
                changed = true;
            }
        }
    }

    if (isSorted(nums)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
