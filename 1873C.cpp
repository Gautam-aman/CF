#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> grid(10);
    for (int i = 0; i < 10; i++) {
        cin >> grid[i];
    }
    int total = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 'X') {
                // compute ring / layer
                int dist = min({ i, j, 9 - i, 9 - j });
                int score = dist + 1;  
                total += score;
            }
        }
    }
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
