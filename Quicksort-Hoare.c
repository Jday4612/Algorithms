#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void quicksort_Hoare(int A[], int low, int high);
int partition_Hoare(int A[], int low, int high);
void quicksort_Lomuto(int A[], int low, int high);
int partition_Lomuto(int A[], int low, int high);

int c_H = 0, s_H = 0, c_L = 0, s_L = 0;

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int n, a[1000], b[1000];

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}

		c_H = 0, s_H = 0, c_L = 0, s_L = 0;
		quicksort_Hoare(a, 0, n - 1);
		quicksort_Lomuto(b, 0, n - 1);

		printf("%d %d %d %d\n", s_H, s_L, c_H, c_L);
	}

	return 0;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort_Hoare(int A[], int low, int high) {
	if (low >= high)
		return;

	int p = partition_Hoare(A, low, high);

	quicksort_Hoare(A, low, p);
	quicksort_Hoare(A, p + 1, high);
}

int partition_Hoare(int A[], int low, int high) {
	int pivot = A[low];
	int i = low - 1;
	int j = high + 1;

	while (1) {
		do {
			i = i + 1;
			c_H++;
		} while (A[i] < pivot); // 비교(comparison) 연산자 ‘<’
		
		do {
			j = j - 1;
			c_H++;
		} while (A[j] > pivot); // 비교(comparison) 연산자 ‘<’
		
		if (i < j) {
			swap(&A[i], &A[j]); // swap 연산
			s_H++;
		}
		else
			return j;
	}
}

void quicksort_Lomuto(int A[], int low, int high) {
	if (low >= high)
		return;

	int p = partition_Lomuto(A, low, high);

	quicksort_Lomuto(A, low, p - 1);
	quicksort_Lomuto(A, p + 1, high);
}

int partition_Lomuto(int A[], int low, int high) {
	int pivot = A[low];
	int j = low;

	for (int i = low + 1; i <= high; i++) {
		c_L++;

		if (A[i] < pivot) { // 비교(comparison) 연산자 ‘<’
			j = j + 1;
			swap(&A[i], &A[j]); // swap 연산
			s_L++;
		}
	}

	int pivot_pos = j;
	swap(&A[pivot_pos], &A[low]); // swap 연산
	s_L++;
	
	return pivot_pos;
}