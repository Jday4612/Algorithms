#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_SIZE 1000
void ShellSort(int a[], int n);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int num;
		int a[MAX_SIZE];

		scanf("%d", &num);
		for (int j = 0; j < num; j++)
			scanf("%d", &a[j]);
		
		ShellSort(a, num);
		printf("\n");
	}

	return 0;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Shell Sort 함수 */
void ShellSort(int a[], int n) {
	int countCmpOps = 0; // 비교 연산자 실행 횟수
	int countSwaps = 0; // swap 함수 실행 횟수

	// Shell sort 알고리즘 구현
	int shrink = 2;
	int gap = n / shrink;

	while (gap > 0) {
		for (int i = gap; i < n; i++) {
			int tmp = a[i];
			int j;

			for (j = i; j >= gap; j -= gap) {
				countCmpOps++;

				if (a[j - gap] > tmp) {
					a[j] = a[j - gap];
					countSwaps++;
				}
				else
					break;
			}
			a[j] = tmp;
		}
		gap /= shrink;
	}
	
	printf("%d %d ", countCmpOps, countSwaps);
}