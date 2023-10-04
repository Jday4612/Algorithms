#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void next_permutation(char* str, int n);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int n;
		char str[27];

		scanf("%d %s", &n, str);
		next_permutation(str, n);
		
		for (int i = 0; i < n; i++)
			printf("%c", str[i]);
		printf("\n");
	}

	return 0;
}

void swap(char* a, char* b) {
	char tmp = *b;
	*b = *a;
	*a = tmp;
}

void next_permutation(char* str, int n) {
	int i = n - 1;
	int j = n - 1;
	int k = n - 1;

	if (n == 1)
		return;

	while (i > 0 && str[i - 1] >= str[i])
		--i;

	if (i != 0) {
		while (str[i - 1] >= str[j])
			--j;

		swap(&str[i - 1], &str[j]);
	}

	while (i < k)
		swap(&str[i++], &str[k--]);
}