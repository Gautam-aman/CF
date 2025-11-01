#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


void solve() {
    int N;
    cin >> N;

    
    struct Rectangle {
        int x1, y1, x2, y2;
    };

    vector<Rectangle> colored(N);
    for (int i = 0; i < N; ++i) {
        cin >> colored[i].x1 >> colored[i].y1 >> colored[i].x2 >> colored[i].y2;
    }

    Rectangle outer;
    cin >> outer.x1 >> outer.y1 >> outer.x2 >> outer.y2;

    int W = outer.x2 - outer.x1;
    int H = outer.y2 - outer.y1;


    set<int> invalidX;

    set<int> invalidY;

    for (const auto& rect : colored) {
        for (int k = rect.x1 + 1; k < rect.x2; ++k) {
            invalidX.insert(k);
        }
        for (int k = rect.y1 + 1; k < rect.y2; ++k) {
            invalidY.insert(k);
        }
    }

    set<int> validX;
    validX.insert(outer.x1); 
    validX.insert(outer.x2);


    set<int> validY;
    validY.insert(outer.y1); 
    validY.insert(outer.y2);

    for (int k = outer.x1 + 1; k < outer.x2; ++k) {
        if (invalidX.find(k) == invalidX.end()) {
            validX.insert(k);
        }
    }

  
    for (int k = outer.y1 + 1; k < outer.y2; ++k) {
        if (invalidY.find(k) == invalidY.end()) {
            validY.insert(k);
        }
    }


    
    int minW = W;
    if (validX.size() > 1) {
        int prevX = *validX.begin();
        for (auto it = next(validX.begin()); it != validX.end(); ++it) {
            minW = min(minW, *it - prevX);
            prevX = *it;
        }
    }

    int minH = H;
    if (validY.size() > 1) {
        int prevY = *validY.begin();
        for (auto it = next(validY.begin()); it != validY.end(); ++it) {
            minH = min(minH, *it - prevY);
            prevY = *it;
        }
    }

    long long min_area = (long long)minW * minH;

    cout << min_area << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}