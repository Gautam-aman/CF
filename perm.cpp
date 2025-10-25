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
    if (n == 2 || n == 3) {
        cout  << "NO SOLUTION" << endl ;
    
    }
    else if (n == 1) cout << "1" << endl;
    else{vector<ll> nums;
    for(int i = 1 ; i <= n ; i++) nums.push_back(i);
    int even = 1;
    int odd = 2 ;

    while(odd <= n){
        cout << odd << " ";
        odd += 2;
    }
    while (even <= n){
        cout << even << " ";
        even +=2;
    }}

    return 0;
}