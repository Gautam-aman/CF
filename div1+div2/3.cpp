#include <iostream>
#include <vector>
#include <numeric>   
#include <algorithm> 


using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;

    vector<int> a(n);
    long long final = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        final += a[i];
    }

    
    sort(a.begin(), a.end());

    int k = final / x;

    long long maxi = 0;
    for (int i = n - k; i < n; ++i) {
        maxi += a[i];
    }
    cout << maxi << "\n";
   
    vector<int> finalorder;
    long long currsum = 0;

    int one = 0;
    int two = n - k;
    int three = n - k;
    int four = n;

    for (int i = 0; i < n; ++i) {
        long long r = currsum % x;

      
        if (three < four && r + a[three] >= x) {
            finalorder.push_back(a[three]);
            currsum += a[three];
            three++;
        } 
       
        else if (one < two) {
            finalorder.push_back(a[one]);
            currsum += a[one];
            one++;
        } 
        else {
            finalorder.push_back(a[three]);
            currsum += a[three];
            three++;
        }
    }

 
    for (int i = 0; i < n; ++i) {
        cout << final_order[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}