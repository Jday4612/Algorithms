#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int CMM(int num[], int i, int j);

int main() {
	int num_test_cases, n, num[11];

	scanf("%d", &num_test_cases); // 테스트 데이터 개수

	while (num_test_cases--) {
		scanf("%d", &n);

		for (int i = 0; i <= n; i++)
			scanf("%d", &num[i]);

		printf("%d\n", CMM(num, 1, n));
	}
}

int CMM(int num[], int i, int j) {
	if (i == j)
		return 0;
	
	int min = INT_MAX;
	for (int k = i; k < j; k++) {
		int tmp = CMM(num, i, k) + CMM(num, k + 1, j) + num[i - 1] * num[k] * num[j];
		
		if (tmp < min)
			min = tmp;
	}

	return min;
}