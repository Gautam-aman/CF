#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;

bool valid(int row , int col , int n){
    return row < n && row >= 0 && col < n && col >= 0 ;
}

bool check(int r , int c , vector<string>&grid , int n ){
    if(grid[r][c] == '#') return false;

    if (valid(r, c - 1, n) && grid[r][c - 1] == '#' && valid(r, c + 1, n) && grid[r][c + 1] == '#') return true;
    if (valid(r, c - 2, n) && grid[r][c - 2] == '#' && valid(r, c - 1, n) && grid[r][c - 1] == '#') return true;
    if (valid(r, c + 1, n) && grid[r][c + 1] == '#' && valid(r, c + 2, n) && grid[r][c + 2] == '#') return true;
    
    if (valid(r - 1, c, n) && grid[r - 1][c] == '#' && valid(r + 1, c, n) && grid[r + 1][c] == '#') return true;
    if (valid(r - 2, c, n) && grid[r - 2][c] == '#' && valid(r - 1, c, n) && grid[r - 1][c] == '#') return true;
    if (valid(r + 1, c, n) && grid[r + 1][c] == '#' && valid(r + 2, c, n) && grid[r + 2][c] == '#') return true;
    
    return false;
}

void dfs(int row , int col , vector<string> &grid , int n , vector<vector<bool>>&visited , int &newblack){
    
    if (!valid(row, col, n)) return;

    if (visited[row][col]) return;

    if (grid[row][col] == '.' && check(row, col, grid, n)) return;
    
    visited[row][col] = true;
    
    if(grid[row][col] =='#'){
        newblack++;
    }

    int drow[] = {-1, 1, 0, 0};
    int dcol[] = {0, 0, -1, 1};

    for(int i  = 0 ; i < 4 ; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        dfs(nrow , ncol  , grid , n , visited , newblack);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    vector<vector<bool>> visited(n , vector<bool>(n , false));
    int black = 0 ;
    int srow = -1 ;
    int scol = -1 ;

    for(int i = 0 ;i < n ; i++){
        cin >> grid[i];
        for(int j = 0 ; j < n ; j++){
            if(grid[i][j] == '#'){
                black++;
                if(srow == -1){
                    srow = i;
                    scol = j;
                }
            }
        }
    }

    if (black == 0) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if (j + 2 < n && grid[i][j] == '#' && grid[i][j + 1] == '#' && grid[i][j + 2] == '#') {
                cout << "NO" << endl; 
                return;
            }
            if (i + 2 < n && grid[i][j] == '#' && grid[i + 1][j] == '#' && grid[i + 2][j] == '#') {
                cout << "NO" << endl;
                return;
            }
        }
    }
     
    int newblack = 0 ;
    dfs(srow , scol , grid , n , visited , newblack);
    
    if (newblack == black){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    fastio;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}