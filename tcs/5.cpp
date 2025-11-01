#include <bits/stdc++.h>
using namespace std;

struct Vert {
    int x, y1, y2;
};

struct Horiz {
    int y, x1, x2;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Vert> verticals;
    vector<Horiz> horizontals;

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) verticals.push_back({x1, min(y1, y2), max(y1, y2)});
        else if (y1 == y2) horizontals.push_back({y1, min(x1, x2), max(x1, x2)});
    }

    if (verticals.size() < 2 || horizontals.size() < 2) {
        cout << 0;
        return 0;
    }

    sort(verticals.begin(), verticals.end(), [](const Vert &a, const Vert &b) {
        if (a.x != b.x) return a.x < b.x;
        if (a.y1 != b.y1) return a.y1 < b.y1;
        return a.y2 < b.y2;
    });

    int V = verticals.size();
    vector<int> vx(V);
    for (int i = 0; i < V; ++i) vx[i] = verticals[i].x;

    unordered_map<long long, int> pairCount;
    pairCount.reserve(horizontals.size() * 4 + 1000);
    pairCount.max_load_factor(0.7f);

    for (const auto &h : horizontals) {
        int l = lower_bound(vx.begin(), vx.end(), h.x1) - vx.begin();
        int r = upper_bound(vx.begin(), vx.end(), h.x2) - vx.begin();
        vector<int> inds;
        for (int idx = l; idx < r; ++idx) {
            const auto &v = verticals[idx];
            if (v.y1 <= h.y && h.y <= v.y2) inds.push_back(idx);
        }
        int k = inds.size();
        for (int a = 0; a < k; ++a) {
            for (int b = a + 1; b < k; ++b) {
                int i = inds[a], j = inds[b];
                long long key = ((long long)i << 32) | (unsigned long long)j;
                ++pairCount[key];
            }
        }
    }

    long long rectangles = 0;
    for (auto &p : pairCount) {
        long long c = p.second;
        if (c >= 2) rectangles += (c * (c - 1)) / 2;
    }

    cout << rectangles;
    return 0;
}
