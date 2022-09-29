#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 1000
void insertionSort(int a[], int n);

int main() {
	int numTestCases;
	
	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int num;
		int a[MAX_SIZE];

		scanf("%d", &num);
		for (int j = 0; j < num; j++)
			scanf("%d", &a[j]);
		
		insertionSort(a, num);
		printf("\n");
	}

	return 0;
}

/* Insertion Sort �Լ� */
void insertionSort(int a[], int n) {
	int countCmpOps = 0; // �� ������ ���� Ƚ��
	int countSwaps = 0; // swap �Լ� ���� Ƚ��

	// insertion sort �˰��� ����
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		int j;
		for (j = i; j > 0; j--) {
			countCmpOps++;

			if (a[j - 1] > tmp) {
				a[j] = a[j - 1];
				countSwaps++;
			}
			else
				break;
		}
		a[j] = tmp;
	}
	
	printf("%d %d ", countCmpOps, countSwaps);
}