

int helper(int i, vector<int>& digits, int n, int index = 0, int number = 0)
{
	if (i == index)
	{	// If number is less than equal to 'N' return '1'.
		return number <= n;
	}

	int ans = 0;
	// Placing all possible digits at index.
	for (int j = 0; j < digits.size(); j++)
	{
		ans += helper(i, digits, n, index + 1, number * 10 + digits[j]);
	}

	return ans;
}

int possibleNumbers(int n, int m, vector<int>& digits)
{
	int d = log10(n) + 1;
	int ans = 0;
	// Finding all possible numbers of all digits.
	for (int i = 1; i <= d; i++)
	{
		ans += helper(i, digits, n);
	}

	return ans;

}
