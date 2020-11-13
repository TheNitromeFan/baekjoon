#include <cstdio>

int main(){
	while(true){
		double len;
		scanf("%lf", &len);
		if(len == 0){
			break;
		}
		int cards = 0;
		double sum = 0;
		while(sum < len){
			++cards;
			sum += 1.0 / (cards + 1);
		}
		printf("%d card(s)\n", cards);
	}
	return 0;
}
