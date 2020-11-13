#include <cstdio>
#include <cstdlib>
#include <cstring>

#define length 8

char *state(int *notes){
	
	int ascending = 1, descending = 1;
	for(int i = 1; i < length; i++){
		if(*(notes+i) < *(notes+i-1)) ascending = 0;
		else if(*(notes+i) > *(notes+i-1)) descending = 0;
		if(!(ascending || descending)) break;
	}
	char *c = (char *)malloc(11 * sizeof(char));
	if(ascending) strcpy(c, "ascending");
	else if(descending) strcpy(c, "descending");
	else strcpy(c, "mixed");
	return c;
}

int main(void){
	
	int *a = (int *)malloc(length * sizeof(int));
	for(int i = 0; i < length; i++) scanf("%d", a+i);
	printf("%s", state(a));
	return 0;
}
