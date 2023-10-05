#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int maxSubsequenceSum(int a[], int start, int end);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int n, f[100], start = -1, end = -1;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);

		printf("%d\n", maxSubsequenceSum(f, 0, n - 1));
	}

	return 0;
}

int max(int a, int b) {
	return a >= b ? a : b;
}

int maxSubsequenceSum(int a[], int start, int end) {
	int left_maxSum = 0, right_maxSum = 0, half, biasedSum, maxSum;

	if (start == end)
		return a[start];
	else {
		half = (start + end) / 2;

		int left_thisSum = 0;
		int right_thisSum = 0;

		for (int i = half; start <= i; i--) {
			left_thisSum += a[i];
			left_maxSum = max(left_maxSum, left_thisSum);
		}

		for (int i = half + 1; i <= end; i++) {
			right_thisSum += a[i];
			right_maxSum = max(right_maxSum, right_thisSum);
		}

		biasedSum = max(maxSubsequenceSum(a, start, half), maxSubsequenceSum(a, half + 1, end));
		maxSum = max(biasedSum, left_maxSum + right_maxSum);

		return maxSum;
	}
}
