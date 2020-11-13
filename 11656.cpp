#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LENGTH 1001


int compare(const void *a, const void *b){
	
	return strcmp(*(char **)a, *(char **)b);
}

int main(void){
	
	char *s = (char *)malloc(MAX_LENGTH * sizeof(char));
	scanf("%s", s);
	int len = strlen(s);
	char **substrings = (char **)malloc(len * sizeof(char *));
	for(int i = 0; i < len; i++){
		*(substrings+i) = (char *)malloc(MAX_LENGTH * sizeof(char));
		for(int j = i; j < len; j++) *(*(substrings+i)+j-i) = *(s+j);
		*(*(substrings+i)+len-i) = '\0';
	}
	free(s);
	qsort(substrings, len, sizeof(char *), compare);
	for(int i = 0; i < len; i++){
		printf(*(substrings+i));
		free(*(substrings+i));
		printf("\n");
	}
	free(substrings);
	return 0;
}
