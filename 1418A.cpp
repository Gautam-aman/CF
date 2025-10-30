#include <bits/stdc++.h>
using namespace std;

// Function to perform ceiling division of a by b
long long ceil_division(long long a, long long b) {
	return (a + b - 1) / b;
}

int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		long long x, y, k;
		cin >> x >> y >> k; // Read the values of x, y, and k for each test case

		// Calculate the number of sticks gained per trade
		long long sticks_gained_per_trade = x - 1; // If we give 1 stick and get x back, we gain x-1 sticks

		// Calculate the total number of sticks needed to craft k torches
		// 1 torch requires 1 stick and 1 coal, hence k torches require k sticks and k coals
		long long sticks_needed = k * y + k - 1;

		long long trades = 0;
		// Calculate the number of trades needed to gain the required number of sticks
		trades += ceil_division(sticks_needed, sticks_gained_per_trade);
		// Add the number of trades needed to get k coals
		trades += k;

		// Output the total number of trades required
		cout << trades << endl;
	}
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
