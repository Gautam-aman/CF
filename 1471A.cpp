#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n, x;
		cin >> n >> x; // Read the size of the array and the integer x
		vector<long long> a(n); // Declare a vector to store the array elements
		long long min = 0, max = 0; // Initialize variables to store min and max beauty
		for (int i = 0; i < n; i++) // Loop to read the array elements
			cin >> a[i];
		
		for (int i = 0; i < n; i++) // Loop to calculate max beauty
		{
			// Add the ceiling of each element divided by x to max
			max += ceil(a[i] * 1.0 / x);
			// Sum up all elements to calculate min later
			min += a[i];
		}

		// Calculate min beauty by taking the ceiling of the total sum divided by x
		min = ceil(min * 1.0 / x);
		// Output the min and max beauty for the current test case
		cout << min << " " << max << endl;
	}
	return 0;
}

// Time Complexity (TC): O(n) = O(10^5)
// Space Complexity (SC): O(n) = O(10^5)
