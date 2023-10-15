#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void merge(int a[], int low, int mid, int high);
void mergeSortIterative(int v[], int n);
int cnt = 0;

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int n, a[100];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		cnt = 0;
		mergeSortIterative(a, n);
		printf("%d\n", cnt);
	}

	return 0;
}

int MIN(int a, int b) {
	return a < b ? a : b;
}

void merge(int a[], int low, int mid, int high) {
	int i, j, k;
	int tmp[100];

	for (i = low; i <= high; i++)
		tmp[i] = a[i];

	i = k = low;
	j = mid + 1;

	while (i <= mid && j <= high) {
		cnt++;

		if (tmp[i] <= tmp[j]) // <---- 핵심연산자(비교연산자)
			a[k++] = tmp[i++];
		else
			a[k++] = tmp[j++];
	}

	while (i <= mid)
		a[k++] = tmp[i++];
	while (j <= high)
		a[k++] = tmp[j++];
}

void mergeSortIterative(int v[], int n) {
	int size = 1;

	while (size < n) {
		for (int i = 0; i < n; i += 2 * size){
			int low = i;
			int mid = low + size - 1;
			int high = MIN(i + 2 * size - 1, n - 1);

			if (mid >= n - 1) // merge할 subarray가 1개일 경우
				break;
			
			merge(v, low, mid, high);
		}
		size *= 2;
	}
}