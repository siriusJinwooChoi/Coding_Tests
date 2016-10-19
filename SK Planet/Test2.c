/*
	SK Planet 2번 문제 (Test 2)
	입력 : 13355
	출력 : 55331

	입력 : 13353
	출력 : 53331


	예외 케이스 : 13531은 return -1, 즉 -1을 리턴해야한다. ( 이미 135 부분이 정렬 되어있으므로)
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