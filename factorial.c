#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_SIZE 1000
int factorial(int n);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int n;

		scanf("%d", &n);

		printf("%d\n", factorial(n) % 1000);
	}

	return 0;
}

/* facotiral ÇÔ¼ö */
int factorial(int n) {
	if (n <= 1)
		return 1;
	else {
		int tmp = n * factorial(n - 1);

		while (1) {
			if (tmp % 10 == 0)
				tmp /= 10;
			else
				break;
		}

		return tmp % 10000;
	}
}