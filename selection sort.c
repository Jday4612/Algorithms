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

/* Selection Sort �Լ� */
void selectionSort(int a[], int n) {
	int countCmpOps = 0; // �� ������ ���� Ƚ��
	int countSwaps = 0; // swap �Լ� ���� Ƚ��

	// selection sort �˰��� ����
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