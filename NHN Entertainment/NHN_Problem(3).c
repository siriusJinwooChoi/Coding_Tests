//3번
/*
  NHN Coding Test 3번 문제
*/

#include <stdio.h>
#include <stdlib.h>


int getInput()
{
    int number = 0;
    if (scanf("%d", &number) <= 0) {
        fprintf(stderr, "can't read a number from stdin\n");
        return -1;
    }

    return number;
}


int main()
{
  	int* numbers = (int*) malloc(sizeof(int));
  	int* origin = (int*) malloc(sizeof(int));  
  	int cnt=0, flag = 0;
  int number = getInput();
  while(1) {
    int i=0, len=0;
    int temp = number;
    if(cnt >= 3) {
      printf("-1\n");
      break;
    }
    else {
      i=0;
  		while(temp > 0) {
	      len++;
	      numbers[i++] = temp % 10;
	      temp /= 10;
	    }
      
	  	int j=0, reversnum = 0, jisu=1;
	  	for(int i=len-1; i>=0; i--) {
		    origin[j] = numbers[i];
        reversnum += (origin[j] * jisu);
        jisu *= 10;
        j++;
		  }
      
      int sum = reversnum + number;
      int tempsum = sum;
      int tlen = 0;
      i=0;
      while(tempsum > 0) {
	      tlen++;
	      numbers[i++] = tempsum % 10;
	      tempsum /= 10;
	    }
      
      for(int i=0; i<tlen/2; i++) {
        if(numbers[i] == numbers[tlen-i-1])
          flag = 1;
        else {
          flag = 0;
          break;
        }
      }
      if(flag == 1) {
        printf("%d\n", sum);
        break;
      }
      number = sum;
      cnt++;
    }
  }
  return 0;
}