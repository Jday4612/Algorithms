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

/* Maximum Contiguous Subsequence Sum �Լ� */
int maxSubsequenceSum(int a[], int start, int end) {
    int half, left, right, mid, check;
    int maxLeft, maxRight, thisSum;

    if (start == end)
        return a[start];
    else {
        //Divide : n ���� �����迭�� ũ�Ⱑ ���� n/2 ���� �κй迭�� ������.
        half = (start + end) / 2;

        //Conquer :ũ�Ⱑ ���� n / 2 ���� �κй迭�� ���Ͽ� recursive �ϰ� ������ �ذ��Ѵ�.
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

        //Combine : "Conquer" �ܰ迡�� ����� ���� ������ ���� ���ӵ� ������ �߾��� ���ļ�\
        ������ �� �����Ƿ� �̷� ��쵵 �ذ��Ͽ��� �Ѵ�.�̸� ���ؼ��� �߾��� �߽����� ��������\
        ���������� �ִ밡 �Ǵ� ���� �߾��� �߽����� ���������� ���������� �ִ밡 �Ǵ� ���� ���Ͽ� ���Ѵ�.
        check = left > right ? left : right; // ���� �Ǵ� �����ʿ� �ִ��� Ȯ��
        
        return mid > check ? mid : check;
    }
}