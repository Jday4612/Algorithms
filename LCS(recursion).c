#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int LCS(int m, int n);
char a[10], b[10];

int main() {
	int num_test_cases, m, n;

	scanf("%d", &num_test_cases); // 테스트 데이터 개수

	while (num_test_cases--) {
		for (int i = 0; i < 10; i++)
			a[i] = b[i] = '\0';

		scanf("%s %s", a, b);
		m = strlen(a);
		n = strlen(b);

		printf("%d\n", LCS(m, n));
	}
}

int LCS(int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	else if (m > 0 && n > 0) {
		if (a[m - 1] == b[n - 1])
			return LCS(m - 1, n - 1) + 1;
		else {
			int c = LCS(m - 1, n);
			int d = LCS(m, n - 1);
			return c > d ? c : d;
		}
	}
}