#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LENGTH 80


int score(char *answers, int length){
	
	int total = 0, streak = 0;
	for(int i = 0; i < length; i++){
		if(*(answers+i) == 'O'){
			streak++;
			total += streak;
		}else streak = 0;
	}
	return total;
}

int main(void){
	
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		char *s = (char *)malloc(MAX_LENGTH * sizeof(char));
		scanf("%s", s);
		int len = strlen(s);
		printf("%d\n", score(s, len));
		free(s);
	}
	return 0;
}
