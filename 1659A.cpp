#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n , r, b;
    cin >> n >> r >> b;
    string s(n , 'R');
    int count = n / b;
    int index = count-1;
    while (index < n){
        s[index] = 'B';
        index += count;
    }

    cout << s << endl;
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}