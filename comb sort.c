#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 1000
void combSort(int a[], int n);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int num;
		int a[MAX_SIZE];

		scanf("%d", &num);
		for (int j = 0; j < num; j++)
			scanf("%d", &a[j]);

		combSort(a, num);
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

/* comb sort �Լ� */
void combSort(int a[], int n)
{
	int countCmpOps = 0; // �� ������ ���� Ƚ��
	int countSwaps = 0; // swap �Լ� ���� Ƚ��

	// comb sort �˰��� ����
	int gap = n;
	double shrink = 1.3;
	int sorted = 0;

	while (sorted == 0) {
		gap /= shrink;
		if (gap <= 1) {
			gap = 1;
			sorted = 1;
		}

		int i = 0;
		while (i+gap < n) {
			if (a[i] > a[i + gap]) {
				swap(&a[i], &a[i + gap]);
				sorted = 0;
				countSwaps++;
			}
			countCmpOps++;
			i++;
		}
	}
	
	printf("%d %d ", countCmpOps, countSwaps);
}