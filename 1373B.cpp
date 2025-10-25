#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    int count = 0;

    for (char c : s) {
        if (!st.empty() && st.top() != c) {
            st.pop();
            count++;
        } else {
            st.push(c);
        }
    }

    if (count % 2 == 0) cout << "NET\n";
    else cout << "DA\n";
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
