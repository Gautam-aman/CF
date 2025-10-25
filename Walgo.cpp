#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;




int main() {
    fastio;

    long long n;
    cin >> n;
    vector<ll> ans;
    ans.push_back(n);
    while (n != 1){
        if (n % 2 ==0){
            n = n/2;
            ans.push_back(n);
        }
        else{
            n = (n*3) + 1;
            ans.push_back(n);
        }
    }

    for(int i =0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}