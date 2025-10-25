#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    long long n , k;
    cin >> n >> k;
    vll vec(n);
    for(int i =0 ; i< n ; i++){
        cin >> vec[i];
    }
    vll ans;
    for(int i =0 ; i < n; i++){
        if(vec[i] % k == 0) ans.push_back(i);
        vec[i] = vec[i] % k;
    }
    vector<pair<ll ,int>> temp;
    for (int i = 0; i < n ; i++){
        temp.push_back({vec[i] , i});
    }
   sort(temp.begin(), temp.end(), [&](pair<long long, long long> a, pair<long long, long long> b) {
			if (a.first != b.first)
				return a.first > b.first;
			return a.second < b.second;
		});
    for(int i =0 ; i < n ; i++){
        if (temp[i].first != 0){
            ans.push_back(temp[i].second);
        }
    }
    for(auto it : ans){
        cout << it+1  << " " ;
    }
    cout << endl;
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}