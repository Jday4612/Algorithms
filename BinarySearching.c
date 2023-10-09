#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binarySearch(int a[], int left, int right, int value);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int n, k, f[100];

		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);

		printf("%d\n", binarySearch(f, 0, n - 1, k));
	}

	return 0;
}

int binarySearch(int a[], int left, int right, int value) {
	int mid;

	if (left > right)
		return -1;
	else {
		mid = (left + right) / 2;

		if (a[mid] == value)
			return mid;
		else if (a[mid] > value)
			return binarySearch(a, left, mid - 1, value);
		else
			return binarySearch(a, mid + 1, right, value);
	}
}
