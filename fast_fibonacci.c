#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int FiboMat(int n);
void pow(int a[][2], int n);
void mul(int a[][2], int r[][2]);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		int n;

		scanf("%d", &n);
		
		printf("%d\n", FiboMat(n));
	}

	return 0;
}

/* FiboMat �Լ� */
int FiboMat(int n) {
	int a[2][2] = { {1, 1}, {1, 0} };

	if (n <= 1)
		return n;

	pow(a, n);

	return a[0][1];
}

/* pow �Լ� */
void pow(int a[][2], int n) {
	int r[2][2] = { {1, 1}, {1, 0} };
	
	if (n <= 1)
		return;

	pow(a, n / 2); // ���� n�� n/2 * n/2���� �����
	mul(a, a); 

	if (n % 2 != 0) // Ȧ���� ���, { {1, 1}, {1, 0} }�� �߰��� �� ���ؾ� ��
		mul(a, r);
}

/* mul �Լ� */
void mul(int a[][2], int r[][2]) {
	int x[2][2];
	
	x[0][0] = (a[0][0] * r[0][0] + a[0][1] * r[1][0]) % 1000;
	x[0][1] = (a[0][0] * r[0][1] + a[0][1] * r[1][1]) % 1000;
	x[1][0] = (a[1][0] * r[0][0] + a[1][1] * r[1][0]) % 1000;
	x[1][1] = (a[1][0] * r[0][1] + a[1][1] * r[1][1]) % 1000;

	a[0][0] = x[0][0];
	a[0][1] = x[0][1];
	a[1][0] = x[1][0];
	a[1][1] = x[1][1];
}