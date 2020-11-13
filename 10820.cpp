#include <cstdio>
#include <cstdlib>

#define MAX_LENGTH 102


int lower, upper, number, white;

void analyze(char *string){
	
	lower = 0;
	upper = 0;
	number = 0;
	white = 0;
	for(int i = 0; *(string+i) != '\n'; i++){
		if(string[i] == ' ') white++;
		else if(string[i] >= '0' && string[i] <= '9') number++;
		else if(string[i] >= 'A' && string[i] <= 'Z') upper++;
		else if(string[i] >= 'a' && string[i] <= 'z') lower++;
	}
}

int main(void){
	
	char *s = (char *)malloc(MAX_LENGTH * sizeof(char));
	while(fgets(s, MAX_LENGTH, stdin) != NULL){
		analyze(s);
		printf("%d %d %d %d\n", lower, upper, number, white);
	}
	free(s);
	return 0;
}
