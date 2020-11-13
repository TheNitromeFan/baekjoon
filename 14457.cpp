#include <cstdio>

void tip(char cows[][11], int n, int x, int y){
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < y; ++j){
			if(cows[i][j] == '0'){
				cows[i][j] = '1';
			}else{
				cows[i][j] = '0';
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	char cows[11][11];
	for(int i = 0; i < n; ++i){
		scanf("%s", cows[i]);
	}
	int flips = 0;
	for(int sum = 2 * n; sum >= 2; --sum){
		for(int i = 1, j = sum - i; i <= n; ++i, --j){
			if(i >= 1 && i <= n && j >= 1 && j <= n && cows[i - 1][j - 1] == '1'){
				tip(cows, n, i, j);
				++flips;
			}
		}
	}
	printf("%d", flips);
	return 0;
}
