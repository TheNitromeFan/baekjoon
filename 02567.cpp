#include <cstdio>

int main(){
	int paper[101][101];
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			paper[i][j] = 0;
	int n;
	scanf("%d", &n);
	for(int a = 0; a < n; a++){
		int left, bottom;
		scanf("%d %d", &left, &bottom);
		for(int i = left; i < left + 10; i++){
			for(int j = bottom; j < bottom + 10; j++){
				if(paper[i][j] == 0){
					paper[i][j] = 1;
				}
			}
		}
	}
	int total = 0;
	for(int i = 0; i <= 100; ++i){
		for(int j = 0; j < 100; ++j){
			if(paper[i][j] != paper[i][j + 1]){
				++total;
			}
		}
	}
	for(int j = 0; j <= 100; ++j){
		for(int i = 0; i < 100; ++i){
			if(paper[i][j] != paper[i + 1][j]){
				++total;
			}
		}
	}
	printf("%d", total);
	return 0;
}
