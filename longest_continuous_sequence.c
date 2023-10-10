#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int maxSubsequenceSum(int a[], int n);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int n, f[1000], result;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);

		result = maxSubsequenceSum(f, n);
		printf("%d\n", result);
	}

	return 0;
}

int maxSubsequenceSum(int a[], int n) {
	int Len = 0, maxLen = 0;

	for (int i = 0; i < n; i++) {
		if (maxLen == n)
			break;

		Len = 0;

		for (int j = i; j < n; j++) {
			if (a[i] <= a[j])
				Len++;
			else {
				i = j - 1;
				break;
			}
		}

		if (Len > maxLen)
			maxLen = Len;
	}

	return maxLen;
}