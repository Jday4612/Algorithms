#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

int check;
void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int low, int high);

int main() {
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i) {
        int n;
        int a[MAX_SIZE];
        check = 0;

        scanf("%d", &n);

        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        mergeSort(a, 0, n - 1);
        printf("%d\n", check);
    }
    return 0;
}

/* merge 함수 */
void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int tmp[MAX_SIZE];

    for (i = low; i <= high; i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        check++;

        if (tmp[i] <= tmp[j])  // <---- 핵심연산자(비교연산자)
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }

    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}

/* merge sort 함수 */
void mergeSort(int v[], int low, int high) {
    int mid;

    if (low == high)
        return; /* base case */

    //Divide
    mid = (low + high) / 2;

    //Conquer
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}