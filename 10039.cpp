#include <cstdio>


int main(void){
	
	int scores[5];
	int total = 0;
	for(int i = 0; i < 5; i++){
		scanf("%d", &scores[i]);
		if(scores[i] < 40) scores[i] = 40;
		total += scores[i];
	}
	printf("%d", total / 5);
	return 0;
}
