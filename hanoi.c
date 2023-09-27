#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi_tower(int n, unsigned long long int k, int a, int b, int c);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	for (int i = 0; i < numTestCases; ++i)
	{
		int n;
		unsigned long long int k;

		scanf("%d %llu", &n, &k);
		hanoi_tower(n, k, 1, 2, 3);
	}

	return 0;
}

void hanoi_tower(int n, unsigned long long int k, int a, int b, int c) {
	if (n == 1) {
		printf("%d %d\n", a, c);
		return;
	}
	else {
		unsigned long long int t = (unsigned long long int)1 << (n - 1);

		if (k < t) {
			hanoi_tower(n - 1, k, a, c, b);
		}
		else if (k == t) {
			printf("%d %d\n", a, c);
		}
		else {
			hanoi_tower(n - 1, k - t, b, a, c);
		}
	}
}
