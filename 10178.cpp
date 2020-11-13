#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int candies, piece;
		scanf("%d %d", &candies, &piece);
		int q = candies / piece, r = candies % piece;
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", q, r);
	}
	return 0;
}
