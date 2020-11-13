#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LENGTH 11


int main(void){
	
	char *number = (char *)malloc(MAX_LENGTH * sizeof(char));
	scanf("%s", number);
	int len = strlen(number);
	for(int i = 0; i < len-1; i++){
		printf("%c", *(number+i));
		if((len - 1 - i) % 3 == 0) printf(",");
	}
	printf("%c", *(number+len-1));
	free(number);
	return 0;
}
