#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num_test_cases;
	int n, a[101];

	scanf("%d", &num_test_cases); // 테스트 데이터 개수
	while (num_test_cases--) {
		scanf("%d", &n); // 주어진 정수의 개수

		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		int cnt = 0, next, tmp;
		for (int j = 1; j <= n; j++) {
			if (a[j] == 0)
				continue;

			cnt++;
			next = a[j];
			a[j] = 0;

			while (next != 0) {
				tmp = next;
				next = a[next];
				a[tmp] = 0;
			}
		}
		printf("%d\n", cnt);
	}
}