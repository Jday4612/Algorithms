#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int maxSubsequenceSum(int a[], int n, int* start, int* end);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int n, f[100], start = -1, end = -1, result;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);

		result = maxSubsequenceSum(f, n, &start, &end);
		printf("%d %d %d\n", result, start, end);
	}

	return 0;
}

int maxSubsequenceSum(int a[], int n, int* start, int* end) {
	int i, j;
	int maxSum = 0, thisSum = 0;
	
	*start = *end = -1;

	for (i = 0, j = 0; j < n; j++) {
		thisSum += a[j];

		if (thisSum > maxSum) {
			if (a[i] == 0)
				i++;

			maxSum = thisSum;
			*start = i;
			*end = j;
		}
		else if (thisSum < 0) {
			i = j + 1;
			thisSum = 0;
		}
	}

	return maxSum;
}
