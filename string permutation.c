#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int cnt = 0;
void permuteString(char* str, int begin, int end);

int main() {
	int numTestCases;

	scanf("%d", &numTestCases);
	for (int i = 0; i < numTestCases; ++i) {
		char str[10];
		int len = 0;
		cnt = 0;

		for (int j = 0; j < 9; j++)
			str[j] = '\0';

		scanf("%s", str);
		for (int k = 0; k < 9; k++) {
			if (str[k] != '\0')
				len++;
		}

		permuteString(str, 0, len);
		printf("%d\n", cnt);
	}

	return 0;
}

void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

/* String Permutation ÇÔ¼ö */
void permuteString(char* str, int begin, int end)
{
	int range = end - begin;

	if (range == 1) {
		int w = 0;

		for (int i = 0; i < 9; i++) {
			if (str[i] == '\0')
				break;

			if (i % 2 == 0)
				w += (int)str[i] - 97;
			else
				w += -1 * ((int)str[i] - 97);
		}

		if (w > 0)
			cnt++;
	}
	else
	{
		for (int i = 0; i < range; i++)
		{
			swap(&str[begin], &str[begin + i]);
			permuteString(str, begin + 1, end);
			swap(&str[begin], &str[begin + i]);
		}
	}
}