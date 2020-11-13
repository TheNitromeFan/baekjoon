#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LENGTH 21
#define MAX_SIZE 30



int is_in(char **already, int size, char *to_compare){
	
	for(int i = 0; i < size; i++)
		if(!strcmp(*(already+i), to_compare)) return i;
	return size;
}

long combinations(int *attire, int choices){
	
	long answer = 1;
	for(int i = 0; i < choices; i++) answer *= *(attire+i) + 1;
	return answer-1;
}

int main(void){
	
	int t;
	scanf("%d", &t);
	for(int a = 0; a < t; a++){
		int n;
		scanf("%d", &n);
		char **types = (char **)malloc(MAX_SIZE * sizeof(char *));
		int *choices = (int *)malloc(MAX_SIZE * sizeof(int));
		for(int i = 0; i < MAX_SIZE; i++) *(choices+i) = 0;
		int index = 0;
		for(int i = 0; i < n; i++){
			char *name = (char *)malloc(MAX_LENGTH * sizeof(char)), *category = (char *)malloc(MAX_LENGTH * sizeof(char));
			scanf("%s %s", name, category);
			int k = is_in(types, index, category);
			if(index == k){
				*(types+index) = (char *)malloc(MAX_LENGTH * sizeof(char));
				strcpy(*(types+index), category);
				++*(choices+index);
				index++;
			}else ++*(choices+k);
			free(name);
			free(category);
		}
		printf("%ld\n", combinations(choices, index));
		for(int i = 0; i < index; i++){
			free(*(types+i));
		}
		free(types);
		free(choices);
	}
	return 0;
}
