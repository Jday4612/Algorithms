#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int low, int high);
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
		mergeSort(a, 0, n - 1);
		printf("%d\n", cnt);
	}

	return 0;
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

void mergeSort(int v[], int low, int high) {
	int mid;

	if (low == high)
		return; /* base case */

	mid = (low + high) / 2;
	
	mergeSort(v, low, mid);
	mergeSort(v, mid + 1, high);
	merge(v, low, mid, high);
}
