//2번
/*
  NHN Coding Test 2번 문제
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int getInput(char** tokens, ssize_t sizeLimit)
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
        tokens[i++] = strdup(word);
        if (i >= sizeLimit) {
            break;
        }
    }
    tokens[i] = NULL;

    return i;
}

int main()
{
    // 표준 입력으로부터 최대 10개의 문자열 토큰을 읽어들임
    ssize_t sizeLimit = 10;
    char** words = (char**) malloc(sizeof(char*) * sizeLimit);
    ssize_t size = getInput(words, sizeLimit);

  	int j=0, wordmo = 0, wordja = 0;
  
  	for (int i = 0; i < size; i++) {
	        char* word = words[i];
      
      		int mo = 0, ja = 0;
      		j=0;
      		while(word[j] != '\0') {
            if((word[j] == 'a') || (word[j] == 'e') || (word[j] == 'i') || (word[j] == 'o') || (word[j] == 'u')) {
	        		mo++;
              if(mo == 2) {
              	wordmo++;
                break;
            	}
              ja = 0;
            }
            else {
              ja++;
              if(ja == 3) {
              	wordja++;
                break;
            	}
              mo = 0;
            }
            j++;
					}
    }
  	printf("%d\n", wordmo);
    printf("%d\n", wordja);

    return 0;
}