#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i+1]){
                ok = false;
                break;
            }
            int mini = min(arr[i] , arr[i+1]);
            arr[i] -= mini;
            arr[i+1] -= mini;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
