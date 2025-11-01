#include <bits/stdc++.h>
using namespace std;

struct Race {
    int x, y, day;
};

vector<vector<int>> adj;
vector<int> match;
vector<bool> visited;
vector<Race> races;

bool can_travel(const Race& r1, const Race& r2) {
    if (r2.day <= r1.day) return false;
    int dist = abs(r1.x - r2.x) + abs(r1.y - r2.y);
    int time = r2.day - r1.day;
    return time >= dist;
}

bool dfs(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    for (int v : adj[u]) {
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    races.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; ++i) cin >> races[i].x >> races[i].y >> races[i].day;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && can_travel(races[i], races[j])) adj[i].push_back(j);
    match.assign(n, -1);
    int size = 0;
    for (int u = 0; u < n; ++u) {
        visited.assign(n, false);
        if (dfs(u)) size++;
    }
    cout << n - size;
    return 0;
}
