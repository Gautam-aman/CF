#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;

bool isPossible(int left, int right, int k, vector<int>& nums, vector<long long>& prefix) {
  
    long long total = prefix[left - 1] + (prefix.back() - prefix[right]);

    
    int totalElem = right - left + 1;
    total += 1LL * totalElem * k;

    
    return (total % 2 == 1);
}

void solveTest() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) cin >> nums[i];

   
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        if (isPossible(l, r, k, nums, prefix))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solveTest();
    return 0;
}
