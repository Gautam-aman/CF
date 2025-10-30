#include <bits/stdc++.h>
using namespace std;


bool isFair(long long n) {
	long long num = n;
	while (num != 0) {
		int x = num % 10; 
		if (x != 0 && n % x != 0) {
			
			return false;
		}
		num /= 10; // Remove last digit
	}
	return true; // All digits passed the test
}

int main() {
	int t;
	cin >> t; // Read number of test cases

	while (t--) {
		long long n;
		cin >> n; // Read input number

		// Keep incrementing n until a fair number is found
		while (!isFair(n)) {
			n += 1;
		}

		cout << n << endl; 
	}
}
