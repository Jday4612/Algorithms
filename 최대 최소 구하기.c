#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count_recursive_call;//�Լ� FindMinMax�� ���ȣ���ϴ� Ƚ���� �����ϴ� ��������

void FindMinMax(int a[], int low, int high, int* max, int* min) {
	count_recursive_call++;
	int min1, min2, max1, max2;

	// base case: ���Ұ� 1���� ���
	if (low == high) {
		*max = a[low];
		*min = a[low];
	}
	// base case: ���Ұ� 2���� ���
	else if (high - low == 1) {
		*max = a[low] > a[high] ? a[low] : a[high];
		*min = a[low] < a[high] ? a[low] : a[high];
	}
	// recursive step: ���Ұ� 2�� �̻��� ���
	else {
		int mid = (low + high) / 2;
		FindMinMax(a, low, mid, &max1, &min1);
		FindMinMax(a, mid + 1, high, &max2, &min2);

		*max = max1 > max2 ? max1 : max2;
		*min = min1 < min2 ? min1 : min2;
	}
}

int main() {
	int num_test_cases;
	int data[100], size;

	scanf("%d", &num_test_cases); // �׽�Ʈ ������ ����

	while (num_test_cases--) {
		scanf("%d", &size); // �־��� ������ ����
		count_recursive_call = 0; // ����Լ� ȣ��Ƚ���� 0���� �ʱ�ȭ
		
		for (int i = 0; i < size; i++) {
			scanf("%d", &data[i]);
		}

		int min = 0, max = 0;
		FindMinMax(data, 0, size - 1, &max, &min);

		printf("%d %d %d\n", max, min, count_recursive_call);
	}
}