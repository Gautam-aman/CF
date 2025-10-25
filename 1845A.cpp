#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve() {
    int n ,k, x;
    cin >> n >> k >> x;

    if (x != 1){
        cout << "Yes" << endl;
        cout << n << endl;
        for(int i = 0 ;  i < n ; i++){
            cout << "1" << " ";
        }
        cout << endl;
        return;
    }
    else{
        if (k ==1 || (k == 2 && (n%2 == 1))){
            cout << "NO" << endl;
            return;
        }
        else{
            cout << "YES" << endl;
            if(n % 2 == 0){
                int totallen = n/2;
                cout << totallen << endl;
                for (int i = 0 ; i < totallen ; i++){
                    cout << "2" << " ";
                }
                cout << endl;
            }
            else{
                int totallen = (n-3)/2;
                cout << totallen +1 << endl;
                for(int i =0 ;i < totallen ; i++){
                    cout << "2" << " ";
                }
                cout << "3";
                cout << endl;
            }
        }
    }

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}