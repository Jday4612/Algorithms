#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_SIZE 1000
int fibonacci(int n);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int n;

		scanf("%d", &n);

		printf("%d\n", fibonacci(n));
	}

	return 0;
}

/* fibonacci ÇÔ¼ö */
int fibonacci(int n) {
	if (n <= 1)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}