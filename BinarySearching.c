#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

int binarySearch(int a[], int left, int right, int value);

int main() {
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i) {
        int n, k;
        int a[MAX_SIZE];

        scanf("%d", &n);
        scanf("%d", &k);

        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        printf("%d\n", binarySearch(a, 0, n - 1, k));
    }
    return 0;
}

/* binarySearch ÇÔ¼ö */
int binarySearch(int a[], int left, int right, int value) {
    int mid;

    if (left > right)
        return -1;
    else {
        //Divide
        mid = (left + right) / 2;

        //Conquer
        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            return binarySearch(a, left, mid - 1, value);
        else
            return binarySearch(a, mid + 1, right, value);
    }
}