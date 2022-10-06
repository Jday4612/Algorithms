#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int GCD(int x, int y);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int a;
		int b;
		int c;
		int d;
		int j;
		int k;
		int t;

		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		scanf("%d", &d);

		if (b >= d)
			t = GCD(b, d);
		else
			t = GCD(d, b);

		a = a * d / t;
		c = c * b / t;

		j = a + c;
		k = b * d / t;

		if (j >= k)
			t = GCD(j, k);
		else
			t = GCD(k, j);

		j /= t;
		k /= t;

		printf("%d %d\n", j, k);
	}

	return 0;
}

/* GCD ÇÔ¼ö */
int GCD(int x, int y)
{
	if (y == 0)
		return x;
	else
		return GCD(y, x % y);
}