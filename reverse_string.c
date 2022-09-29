#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void reverseString(char* str, int first, int last);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		char str[100];
		int len = 0;

		for (int j = 0; j < 100; j++)
			str[j] = '\0';

		scanf("%s", str);
		for (int k = 0; k < 100; k++) {
			if (str[k] != '\0')
				len++;
		}

		reverseString(str, 0, len - 1);
		printf("%s\n", str);
	}

	return 0;
}

void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Reverse String ÇÔ¼ö */
void reverseString(char* str, int first, int last)
{
	if (first < last) {
		swap(&str[first], &str[last]);
		reverseString(str, first + 1, last - 1);
	}
}