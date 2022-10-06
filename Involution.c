#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Involution(int a, int n);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int a;
		int n;

		scanf("%d", &a);
		scanf("%d", &n);

		printf("%d\n", Involution(a, n) % 1000);
	}

	return 0;
}

/* Involution ÇÔ¼ö */
int Involution(int a, int n)
{
	int half;

	if (n == 0)
		return 1;

	if (n % 2 == 0) {
		half = Involution(a, n / 2);
		return half * half % 1000;
	}
	else {
		half = Involution(a, (n - 1) / 2);
		return a * half * half % 1000;
	}
}