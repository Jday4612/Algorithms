#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int cnt = 0;
int s[10] = {0, };
void hanoi(int n, int a, int b, int c);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int n;

		scanf("%d", &n);
		cnt = 0;
		for (int j = 0; j < 10; j++)
			s[j] = 0;

		hanoi(n, 1, 2, 3);
		printf("\n");
	}

	return 0;
}

/* hanoi ÇÔ¼ö */
void hanoi(int n, int a, int b, int c) {
	if (n > 0)
	{
		hanoi(n - 1, a, c, b);

		if (a == 3) {
			s[cnt] = 0;
			cnt--;
			printf("%d ", s[cnt]);
		}
		
		if (c == 3) {
			cnt++;
			s[cnt] = n;
			printf("%d ", s[cnt]);
		}

		hanoi(n - 1, b, a, c);
	}
}