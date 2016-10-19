//1번
/*
  NHN Coding Test 1번 문제
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

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
    ssize_t size = getInput(numbers, sizeLimit);

    // 다음과 같은 방식으로 numbers 벡터와 number 변수로 사용할 수 있음
  int min = abs(numbers[0] - numbers[1]);
  int sum = numbers[0] + numbers[1];
  int num1 = numbers[0];
  int num2 = numbers[1];
 
  for(int i=0; i<size; i++) {
    for(int j=1; j<size; j++) {
      if(min > abs(numbers[j-1] - numbers[j])) {
        if(sum > numbers[j-1]+numbers[j]) {
        	min = abs(numbers[j-1] - numbers[j]);
          num1 = numbers[j-1];
        	num2 = numbers[j];
          sum = numbers[j-1]+numbers[j];
        }
      }
      else {
        int temp = numbers[j-1];
        numbers[j-1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
  printf("%d %d\n", num1, num2);
    return 0;
}