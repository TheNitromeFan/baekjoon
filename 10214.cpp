#include <cstdio>


int main(void){
	
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int y = 0, k = 0;
		int a, b;
		for(int inning = 1; inning <= 9; inning++){
			scanf("%d %d", &a, &b);
			y += a;
			k += b;
		}
		if(y > k) printf("Yonsei\n");
		else if(y < k)printf("Korea\n");
		else printf("Draw\n");
	}
	return 0;
}
