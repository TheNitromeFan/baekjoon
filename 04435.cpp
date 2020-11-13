#include <cstdio>

int main(){
	int good[7] = {0, 1, 2, 3, 3, 4, 10};
	int evil[8] = {0, 1, 2, 2, 2, 3, 5, 10};
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int g = 0, e = 0;
		for(int j = 1; j <= 6; ++j){
			int x;
			scanf("%d", &x);
			g += x * good[j];
		}
		for(int j = 1; j <= 7; ++j){
			int x;
			scanf("%d", &x);
			e += x * evil[j];
		}
		printf("Battle %d: ", i);
		if(g > e){
			printf("Good triumphs over Evil\n");
		}else if(g < e){
			printf("Evil eradicates all trace of Good\n");
		}else{
			printf("No victor on this battle field\n");
		}
	}
	return 0;
}
