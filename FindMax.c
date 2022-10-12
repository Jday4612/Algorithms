#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100
#define MAX(a,b) ((a)>(b)?(a):(b))

int recurMax(int a[], int left, int right);

int main() {
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i) {
        int n, result;
        int a[MAX_SIZE];

        scanf("%d", &n);

        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        result = recurMax(a, 0, n - 1);

        printf("%d\n", result);
    }
    return 0;
}

/* Find Max ÇÔ¼ö */
int recurMax(int a[], int left, int right)
{
    int half, maxLeft, maxRight;

    if (left == right)
        return a[left];
    else
    {
        //Divide
        half = (left + right) / 2;

        //Conquer
        maxLeft = recurMax(a, left, half);
        maxRight = recurMax(a, half + 1, right);

        //Combine
        return MAX(maxLeft, maxRight);
    }
}