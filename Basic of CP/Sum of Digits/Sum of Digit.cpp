// C program to compute sum of digits in
// number.
#include <iostream>
using namespace std;

/* Function to get sum of digits */
class gfg {
public:
	int getSum(int n)
	{
		int sum = 0;
		while (n != 0) {
			sum = sum + n % 10;
			n = n / 10;
		}
		return sum;
	}
};

// Driver code
int main()
{
	gfg g;
	int n = 687;
	cout << g.getSum(n);
	return 0;
}
// This code is contributed by Soumik


// C++ implementation of the above approach
#include <iostream>
using namespace std;
int getSum(string str)
{
	int sum = 0;

	// Traversing through the string
	for (int i = 0; i < str.length(); i++) {
		// Since ascii value of
		// numbers starts from 48
		// so we subtract it from sum
		sum = sum + str[i] - 48;
	}
	return sum;
}

// Driver Code
int main()
{
	string st = "123456789123456789123422";
	cout << getSum(st);
	return 0;
}
