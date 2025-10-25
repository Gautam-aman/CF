#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Check if all elements are equal
    bool all_equal = true;
    for(int i = 1; i < n; i++){
        if(a[i] != a[0]){
            all_equal = false;
            break;
        }
    }
    if(all_equal){
        cout << -1 << "\n";
        return;
    }

    // Sort array
    sort(a.begin(), a.end());
    vector<long long> b;
    vector<long long> c;

   int maxi = *max_element(a.begin() , a.end());
   for(int i= 0 ; i < n ; i++){
        if (a[i] != maxi){
            b.push_back(a[i]);
        }
        else c.push_back(a[i]);
   }

    cout << b.size() << " " << c.size() << "\n";
    for(auto x: b) cout << x << " ";
    cout << "\n";
    for(auto x: c) cout << x << " ";
    cout << "\n";
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
