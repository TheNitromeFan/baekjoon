#include <cstdio>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int heads = 0, tails = 0;
		for(int i = 0; i < n; ++i){
			int game;
			scanf("%d", &game);
			if(game){
				++tails;
			}else{
				++heads;
			}
		}
		printf("Mary won %d times and John won %d times\n", heads, tails);
	}
	return 0;
}
