#include <cstdio>

#define MAX 10000000

int cards[2*MAX + 1];

int main(void){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int card;
		scanf("%d", &card);
		cards[card+MAX] = 1;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int hand;
		scanf("%d", &hand);
		printf("%d ", cards[hand+MAX]);
	}
	return 0;
}
