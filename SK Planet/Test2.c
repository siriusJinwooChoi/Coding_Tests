/*
	SK Planet 2�� ���� (Test 2)
	�Է� : 13355
	��� : 55331

	�Է� : 13353
	��� : 53331


	���� ���̽� : 13531�� return -1, �� -1�� �����ؾ��Ѵ�. ( �̹� 135 �κ��� ���� �Ǿ������Ƿ�)
*/

/*
#include <stdio.h>

int func2(int num);

int func2(int num) {
	int tmp, i;
	int arr[10] = { 0, };
	int sum = 0, jisu = 1;

	while (num > 0) {
		i = num % 10;
		arr[i] = arr[i] + 1;
		num /= 10;
	}
	for (i = 0; i < 10; i++) {
		while (arr[i] > 0) {
			tmp = i * jisu;
			sum += tmp;
			jisu *= 10;
			arr[i]--;
		}
	}
	return sum;
}

int main() {
	int num, result;

	scanf_s("%d", &num);

	result = func2(num);
	printf("%d\n", result);

	return 0;
}
*/