#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100
int maxSubsequenceSum(int a[], int n, int* start, int* end);

int main() {
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i) {
        int n, result;
        int a[MAX_SIZE];
        int start = 0;
        int end = 0;

        scanf("%d", &n);

        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        result = maxSubsequenceSum(a, n, &start, &end);
        printf("%d %d %d\n", result, start, end);
    }
    return 0;
}

/* Maximum Contiguous Subsequence Sum ÇÔ¼ö */
int maxSubsequenceSum(int a[], int n, int* start, int* end) {
    int i, j;
    int maxSum = 0, thisSum = 0;

    *start = *end = -1;

    for (i = 0, j = 0; j < n; j++) {
        thisSum += a[j];

        if (thisSum > maxSum) {
            if (a[i] == 0)
                i++;

            maxSum = thisSum;
            *start = i;
            *end = j;
        }
        else if (thisSum < 0) {
            i = j + 1;
            thisSum = 0;
        }
    }

    if (maxSum < 0) {
        maxSum = 0;
        *start = *end = -1;
    }

    return maxSum;
}