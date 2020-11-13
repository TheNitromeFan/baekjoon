#include <cstdio>

int main(){
	char card[102][102];
	int r, c;
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; ++i){
		scanf("%s", card[i]);
	}
	for(int i = 0; i < r; ++i){
		for(int j = c; j < 2*c; ++j){
			card[i][j] = card[i][2*c-1-j];
		}
	}
	for(int i = r; i < 2*r; ++i){
		for(int j = 0; j < 2*c; ++j){
			card[i][j] = card[2*r-1-i][j];
		}
	}
	int a, b;
	scanf("%d %d", &a, &b);
	--a;
	--b;
	if(card[a][b] == '.'){
		card[a][b] = '#';
	}else{
		card[a][b] = '.';
	}
	for(int i = 0; i < 2*r; ++i){
		for(int j = 0; j < 2*c; ++j){
			printf("%c", card[i][j]);
		}
		printf("\n");
	}
	return 0;
}
