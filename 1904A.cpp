#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};
void solve() {
    int a , b ;
    cin >> a >> b;
    int x_king , y_king;
    cin >> x_king >> y_king;
    int x_queen , y_queen ;
    cin >> x_queen >> y_queen;

    set<pair<int , int>> king , queen;

    for(int i =0 ; i < 4 ; i++){

        // all moves by king
        king.insert({x_king + dx[i]*a , y_king + dy[i] * b});
        king.insert({x_king + dx[i]*b, y_king + dy[i] * a});

        // all moves by queen
        queen.insert({x_queen + dx[i] * a  , y_queen + dy[i] * b});

        queen.insert({x_queen + dx[i] * b  , y_queen + dy[i] * a});

    }

    int count = 0 ;
    for(auto it : king){
        if (queen.find(it) != queen.end()) count++;
    }

    cout << count << endl;

}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}