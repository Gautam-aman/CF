#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <climits>
#include <random>
#include <chrono>

using namespace std;
using ll = long long;

const int MAX_VAL = 2000002;
vector<int> spf(MAX_VAL);

void sieve() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void get_prime_factors(int x, set<int>& factors_set) {
    if (x <= 1) return;
    while (x != 1) {
        int p = spf[x];
        factors_set.insert(p);
        while (x % p == 0) x /= p;
    }
}

// Mersenne Twister random number generator, seeded with the current time
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // --- Step 1: Check for cost 0 solution ---
    static vector<bool> seen_prime(MAX_VAL, false);
    vector<int> used_primes_in_testcase;
    bool has_common_factor = false;

    for (int val : a) {
        set<int> temp_factors;
        get_prime_factors(val, temp_factors);
        for (int p : temp_factors) {
            if (seen_prime[p]) {
                has_common_factor = true;
                break;
            }
            seen_prime[p] = true;
            used_primes_in_testcase.push_back(p);
        }
        if (has_common_factor) break;
    }
    for (int p : used_primes_in_testcase) {
        seen_prime[p] = false;
    }
    if (has_common_factor) {
        cout << 0 << "\n";
        return;
    }

    // --- Step 2: Hybrid selection of indices ---
    set<int> indices_to_check;
    int k = 25; // A reasonable number of indices to check from each part
    
    // Add first k and last k indices
    for(int i = 0; i < n && i < k; ++i) {
        indices_to_check.insert(i);
        indices_to_check.insert(n - 1 - i);
    }
    // Add k random indices
    uniform_int_distribution<int> dist(0, n - 1);
    for (int i = 0; i < k; ++i) {
        indices_to_check.insert(dist(rng));
    }

    // --- Step 3: Generate candidate primes from these selected indices ---
    set<int> candidate_primes;
    for (int i : indices_to_check) {
        if (a[i] > 1) get_prime_factors(a[i] - 1, candidate_primes);
        get_prime_factors(a[i], candidate_primes);
        get_prime_factors(a[i] + 1, candidate_primes);
    }

    // --- Step 4: Run the deterministic algorithm on the reduced prime set ---
    ll ans = LLONG_MAX;
    for (int p : candidate_primes) {
        ll min1 = LLONG_MAX, min2 = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            ll cost = 0;
            int remainder = a[i] % p;
            if (remainder != 0) {
                cost = (ll)(p - remainder) * b[i];
            }
            
            if (cost < min1) {
                min2 = min1;
                min1 = cost;
            } else if (cost < min2) {
                min2 = cost;
            }
        }
        ans = min(ans, min1 + min2);
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}