#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int a = 0, b = 0;
		int cards[2][20];
		for(int i = 0; i < 2; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &cards[i][j]);
			}
		}
		for(int j = 0; j < n; ++j){
			if(cards[0][j] == cards[1][j]){
				continue;
			}else if(cards[0][j] > cards[1][j]){
				if(cards[0][j] == 2 && cards[1][j] == 1){
					b += 6;
				}else if(cards[0][j] - cards[1][j] == 1){
					b += cards[0][j] + cards[1][j];
				}else{
					a += cards[0][j];
				}
			}else{
				if(cards[1][j] == 2 && cards[0][j] == 1){
					a += 6;
				}else if(cards[1][j] - cards[0][j] == 1){
					a += cards[0][j] + cards[1][j];
				}else{
					b += cards[1][j];
				}
			}
		}
		printf("A has %d points. B has %d points.\n\n", a, b);
	}
	return 0;
}
