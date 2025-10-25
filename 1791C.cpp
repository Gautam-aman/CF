#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n ;
    cin >> n ;
    string s ;
    cin >> s;
    int left = 0 ;
    int right = n - 1 ;
    while (s[left] != s[right]){
        left++;
        right--;
    }
    int len = right -left +1;
    int finallen = n - len;
    cout << finallen << endl;
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}