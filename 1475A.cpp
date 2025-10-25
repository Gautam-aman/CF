#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n;
		cin >> n; // Read the integer n for the current test case

		// Continuously divide n by 2 to remove all factors of 2
		while (n % 2 == 0)
			n /= 2;

		// After removing all factors of 2, if n is greater than 1,
		// it means n has an odd divisor greater than 1
		if (n > 1)
			cout << "YES" << endl; // Output YES if an odd divisor exists
		else
			cout << "NO" << endl; // Output NO if no odd divisor exists
	}
	return 0;
}

// Time Complexity (TC): O(log2(n)) = O(log2(10^14)) = O(50)
// Space Complexity (SC): O(1)
