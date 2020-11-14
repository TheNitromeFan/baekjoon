#include <cstdio>

int main(){
	int cards[12] = {0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 16, 4};
	int n;
	scanf("%d", &n);
	int x = 21;
	for(int i = 0; i < n; ++i){
		int card;
		scanf("%d", &card);
		x -= card;
		--cards[card];
	}
	int greater = 0, lessequal = 0;
	for(int val = 11; val > x; --val){
		greater += cards[val];
	}
	for(int val = 2; val <= x; ++val){
		lessequal += cards[val];
	}
	printf("%s", greater >= lessequal ? "DOSTA" : "VUCI");
	return 0;
}
