#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num_test_cases;
	int a[1000], n, cnt, max;

	scanf("%d", &num_test_cases); // 테스트 데이터 개수

	while (num_test_cases--) {
		scanf("%d", &n); // 주어진 정수의 개수
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		max = 1, cnt = 1;
		for (int j = 1; j < n; j++) {
			if (a[j - 1] <= a[j])
				cnt++;
			else {
				if (max < cnt)
					max = cnt;

				cnt = 1;
			}
		}

		if (max < cnt)
			max = cnt;

		printf("%d\n", max);
	}
}