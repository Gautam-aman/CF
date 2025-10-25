#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;


int main() {
    fastio;

    int n ;
    cin >> n;
    int mini = 1e9;
    for (int i = 0 ;i < n;i++){
        int value;
        cin >> value;
        value = abs(value);
        mini = min(mini ,value);
    }

    cout << mini << "\n";

    return 0;
}