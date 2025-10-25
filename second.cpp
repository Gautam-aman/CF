#include<bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

int main(){

    fastio

    int t ; 
    cin >> t;
    while (t--){
        int n ;
        int k;
        cin >> n;
        cin>> k;
        vector<int> values(n);
        for (int i =0 ; i < n ;i++){
            cin >> values[i];
        }
        vector<int> copy = values;
        sort(copy.begin(), copy.end());
        if ( k == 1){
            if (copy == values){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else {
            cout << "YES\n";
        }
        
    }

    return 0;

}