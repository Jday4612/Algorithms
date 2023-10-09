#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100
#define MAX(a,b) ((a)>(b)?(a):(b))
int recurMax(int a[], int left, int right);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int n, f[100];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);

		printf("%d\n", recurMax(f, 0, n - 1));
	}

	return 0;
}

int recurMax(int a[], int left, int right) {
	int half;

	if (left == right)
		return a[left];
	else {
		half = (left + right) / 2;
		return MAX(recurMax(a, left, half),
			recurMax(a, half + 1, right));
	}
}
