#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 1000
void selectionSort(int a[], int n);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int num;
		int a[MAX_SIZE];

		scanf("%d", &num);
		for (int j = 0; j < num; j++)
			scanf("%d", &a[j]);

		selectionSort(a, num);
		printf("\n");
	}

	return 0;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Selection Sort 함수 */
void selectionSort(int a[], int n) {
	int countCmpOps = 0; // 비교 연산자 실행 횟수
	int countSwaps = 0; // swap 함수 실행 횟수

	// selection sort 알고리즘 구현
	for (int i = 0; i < n - 1; i++) {
		int jMin = i;

		for (int j = i + 1; j < n; j++) {
			if (a[jMin] > a[j])
				jMin = j;
			countCmpOps++;
		}

		if (jMin != i) {
			swap(&a[jMin], &a[i]);
			countSwaps++;
		}
	}

	printf("%d %d ", countCmpOps, countSwaps);
}