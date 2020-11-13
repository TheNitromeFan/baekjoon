#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LENGTH 16


int *phone_number(char *word, int length){
	
	int *numbers = (int *)malloc(length * sizeof(int));
	for(int i = 0; i < length; i++){
		char letter = *(word+i);
		int number;
		if(letter < 'D') number = 2;
        else if(letter < 'G') number = 3;
        else if(letter < 'J') number = 4;
        else if(letter < 'M') number = 5;
        else if(letter < 'P') number = 6;
        else if(letter < 'T') number = 7;
        else if(letter < 'W') number = 8;
        else number = 9;
    	*(numbers+i) = number;
	}
	return numbers;
}

int time(char *word, int length){
	
	int *phone = phone_number(word, length);
	int total = 0;
	for(int i = 0; i < length; i++) total += *(phone+i) + 1;
	return total;
}

int main(void){
	
	char *s = (char *)malloc(MAX_LENGTH * sizeof(char));
	scanf("%s", s);
	int len = strlen(s);
	printf("%d", time(s, len));
	free(s);
	return 0;
}
