#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int CMM(int num[], int i, int j);
int M[101][101];

int main() {
	int num_test_cases, n, num[101];

	scanf("%d", &num_test_cases); // 테스트 데이터 개수

	while (num_test_cases--) {
		scanf("%d", &n);

		for (int i = 0; i <= n; i++)
			scanf("%d", &num[i]);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++)
				M[i][j] = 0;
		}

		printf("%d\n", CMM(num, 1, n));
	}
}

int CMM(int num[], int i, int j) {
	if (i == j)
		return 0;
	
	int min = INT_MAX;
	for (int k = i; k < j; k++) {
		int a, b, tmp;
		
		if (M[i][k])
			a = M[i][k];
		else
			a = M[i][k] = CMM(num, i, k);

		if (M[k + 1][j])
			b = M[k + 1][j];
		else
			b = M[k + 1][j] = CMM(num, k + 1, j);
			
		tmp = a + b + num[i - 1] * num[k] * num[j];
		
		if (tmp < min)
			min = tmp;
	}

	return M[i][j] = min;
}