#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int a, b;

		scanf("%d", &a);
		scanf("%d", &b);

		printf("%d\n", gcd(a, b));
	}
	return 0;
}

/* gcd ÇÔ¼ö */
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}