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

/* Shell Sort �Լ� */
void ShellSort(int a[], int n) {
	int countCmpOps = 0; // �� ������ ���� Ƚ��
	int countSwaps = 0; // swap �Լ� ���� Ƚ��

	// Shell sort �˰��� ����
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