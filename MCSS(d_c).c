#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100
int maxSubsequenceSum(int a[], int start, int end);

int main() {
    int numTestCases;

    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i) {
        int n, result;
        int a[MAX_SIZE];

        scanf("%d", &n);

        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);

        result = maxSubsequenceSum(a, 0, n - 1);

        if (result < 0)
            printf("0\n");
        else
            printf("%d\n", result);
    }
    return 0;
}

/* Maximum Contiguous Subsequence Sum 함수 */
int maxSubsequenceSum(int a[], int start, int end) {
    int half, left, right, mid, check;
    int maxLeft, maxRight, thisSum;

    if (start == end)
        return a[start];
    else {
        //Divide : n 개의 정수배열을 크기가 각각 n/2 개인 부분배열로 나눈다.
        half = (start + end) / 2;

        //Conquer :크기가 각각 n / 2 개인 부분배열에 대하여 recursive 하게 문제를 해결한다.
        maxLeft = a[half] - 1;
        thisSum = 0;
        for (int i = half; start <= i; i--) {
            thisSum += a[i];
            maxLeft = thisSum > maxLeft ? thisSum : maxLeft;
        }

        maxRight = a[half + 1] - 1;
        thisSum = 0;
        for (int i = half + 1; i <= end; i++) {
            thisSum += a[i];
            maxRight = thisSum > maxRight ? thisSum : maxRight;
        }
        
        mid = maxLeft + maxRight;
        left = maxSubsequenceSum(a, start, half);
        right = maxSubsequenceSum(a, half + 1, end);

        //Combine : "Conquer" 단계에서 계산한 값과 다음과 같이 연속된 구간이 중앙을 걸쳐서\
        존재할 수 있으므로 이런 경우도 해결하여야 한다.이를 위해서는 중앙을 중심으로 왼쪽으로\
        연속적으로 최대가 되는 값과 중앙을 중심으로 오른쪽으로 연속적으로 최대가 되는 값을 구하여 합한다.
        check = left > right ? left : right; // 왼쪽 또는 오른쪽에 있는지 확인
        
        return mid > check ? mid : check;
    }
}