#include <cstdio>

bool valid_board(long long board[][500], int n){
	long long sum = 0;
	for(int j = 0; j < n; ++j){
		sum += board[0][j];
	}
	long long sum1;
	for(int i = 1; i < n; ++i){
		sum1 = 0;
		for(int j = 0; j < n; ++j){
			sum1 += board[i][j];
		}
		if(sum != sum1){
			return false;
		}
	}
	for(int j = 0; j < n; ++j){
		sum1 = 0;
		for(int i = 0; i < n; ++i){
			sum1 += board[i][j];
		}
		if(sum != sum1){
			return false;
		}
	}
	sum1 = 0;
	for(int i = 0; i < n; ++i){
		sum1 += board[i][i];
	}
	if(sum != sum1){
		return false;
	}
	sum1 = 0;
	for(int i = 0; i < n; ++i){
		sum1 += board[i][n - 1 - i];
	}
	if(sum != sum1){
		return false;
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	int x = 0, y = 0;
	long long block[500][500];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%lld", &block[i][j]);
			if(block[i][j] == 0){
				x = i;
				y = j;
			}
		}
	}
	long long sum1 = 0, sum2 = 0;
	for(int j = 0; j < n; ++j){
		sum1 += block[x][j];
		sum2 += block[(x + 1) % n][j];
	}
	block[x][y] = sum2 - sum1;
	printf("%lld", valid_board(block, n) ? block[x][y] : -1);
	return 0;
}
