#include <cstdio>
#include <cstdlib>


int compare(const void *a, const void *b){
	
	return *(int *)a - *(int *)b;
}

int score(int *judges){
	
	qsort(judges, 5, sizeof(int), compare);
	if(*(judges+3) - *(judges+1) >= 4) return 0;
	else return *(judges+1) + *(judges+2) + *(judges+3);
}

int main(void){
	
	int t;
	scanf("%d", &t);
	int *j = (int *)malloc(5 * sizeof(int));
	for(int a = 0; a < t; a++){
		for(int i = 0; i < 5; i++)
			scanf("%d", j+i);
		int s = score(j);
		if(s) printf("%d\n", s);
		else printf("KIN\n");
	}
	free(j);
	return 0;
}
