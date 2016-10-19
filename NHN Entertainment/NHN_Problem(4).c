//4번
/*
  NHN Coding Test 4번 문제
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int getInput(int* tokens, ssize_t sizeLimit)
{
    char* line = NULL;
    size_t lineCap = 0;
    ssize_t lineLen;
    lineLen = getline(&line, &lineCap, stdin);
    if (lineLen < 0) {
        fprintf(stderr, "can't read a line from stdin, %s\n", strerror(errno));
        return -1;
    }

    char *sep = " \n";
    char *brkt;
    int i = 0;
    for (char* word = strtok_r(line, sep, &brkt); word != NULL; word = strtok_r(NULL, sep, &brkt)) {
        tokens[i++] = atoi(word);
        if (i >= sizeLimit) {
            break;
        }
    }

    return i;
}

int main()
{
    // 표준 입력으로부터 최대 10개의 자연수를 읽어들임
    ssize_t sizeLimit = 10;
    int* numbers = (int*) malloc(sizeof(int) * sizeLimit);
  	int* listnumbers = (int*) malloc(sizeof(int) * sizeLimit);
    ssize_t size = getInput(numbers, sizeLimit);

    // 다음과 같은 방식으로 numbers 벡터와 number 변수로 사용할 수 있음
    int len=0, sum=0;
    for (int i = 0; i < size; i++) {
        int number = numbers[i];
      	int temp= number;
      	while(temp > 10) {
	      	len++;
	      	numbers[i++] = temp % 10;
	      	temp /= 10;
	    	}
      	listnumbers[i] = number;
      	sum += number;
    }
  	int min = 0, max=0;
  	for(int j=0; j<size; j++)
    	printf("%d", listnumbers[j]);
    return 0;
}