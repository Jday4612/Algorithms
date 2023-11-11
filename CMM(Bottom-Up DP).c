#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int minmult(int n, int d[], int P[][101]);
void order(int i, int j);
int P[101][101];

int main() {
	int num_test_cases, n, num[101], cnt;

	scanf("%d", &num_test_cases); // 테스트 데이터 개수

	while (num_test_cases--) {
		scanf("%d", &n);

		for (int i = 0; i <= n; i++)
			scanf("%d", &num[i]);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++)
				P[i][j] = 0;
		}

		cnt = minmult(n, num, P);
		order(1, n);
		printf("\n%d\n", cnt);
	}
}

int minmult(int n, int d[], int P[][101]) {
	int i, j, k, diagonal;
	int M[101][101] = { 0, };
	
	for (diagonal = 1; diagonal < n; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;

			int tmp, min = INT_MAX, index = i;
			for (k = i; k < j; k++) {
				tmp = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
				
				if (tmp < min) {
					min = tmp;
					index = k;
				}
			}

			M[i][j] = min;
			P[i][j] = index;
		}
	}

	return M[1][n];
}

void order(int i, int j) {
	if (i == j)
		printf("M%d", i);
	else {
		int k = P[i][j];
		printf("(");
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}