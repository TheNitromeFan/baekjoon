#include <cstdio>
#include <cstdlib>
#include <cstring>


char *kmp(char *names, int length){
	
	char *s = (char *)malloc(length * sizeof(char));
	*s = '\0';
	for(int i = 0; i < length; i++){
		if(i == 0 || *(names+i-1) == '-'){
			char *temp = (char *)malloc(2 * sizeof(char));
			*temp = *(names+i);
			*(temp+1) = '\0';
			strcat(s, temp);
			free(temp);
		}
	}
	return s;
}

int main(void){
	
	char *line = (char *)malloc(101 * sizeof(char));
	scanf("%s", line);
	int len = strlen(line);
	printf("%s", kmp(line, len));
	free(line);
	return 0;
}
