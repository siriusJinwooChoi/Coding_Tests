/*
	SK Planet 3������(Test 3)

	CA�� CC��, AA�� A��, CC�� C�� ��ȯ..
	��, ABBCC�� AC�� ��.

	AB -> AA
	BA -> AA
	CB -> CC
	BC -> CC
	AA -> A
	CC -> C

	�Է� : ABBCC
	��� : AC
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* func3(char c[]);

char* func3(char c[]) {
	int k, i = 0, len = 0;

	while (c[i++] != '\0') {
		len++;
	}

	for (i = 1; i <= len; i++) {
		if (c[i - 1] == 'A' && c[i] == 'B') {
			c[i] = 'A';
			i -= 1;
		}
		else if (c[i - 1] == 'B' && c[i] == 'A') {
			c[i - 1] = 'A';
			i -= 1;
		}
		else if (c[i - 1] == 'B' && c[i] == 'C') {
			c[i - 1] = 'C';
			i -= 1;
		}
		else if (c[i - 1] == 'C' && c[i] == 'B') {
			c[i] = 'C';
			i -= 1;
		}
		else if (c[i - 1] == 'A' && c[i] == 'A') {
			for (k = i; k <= len; k++)
				c[k - 1] = c[k];
			len--;
			i -= 1;
		}
		else if (c[i - 1] == 'C' && c[i] == 'C') {
			for (k = i; k <= len; k++)
				c[k-1] = c[k];
			len--;
			i -= 1;
		}
	}

	return c;
}

int main() {
	int i=0, len = 0;
	char str[100];

	while ((str[i] = fgetc(stdin)) != '\n') {
		len++;
		i++;
	}

	char *result;
	result = (char *)malloc(sizeof(str));

	str[i] = '\0';

	result = func3(str);
	printf("result = %s\n", result);

	return 0;
}