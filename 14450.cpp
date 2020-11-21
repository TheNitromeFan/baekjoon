#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

int compute(int games[][21][3], int p[100000], int n, int k, int h){
	if(n < 0 || k < 0 || h < 0){
		return 0;
	}else if(n == 0){
		return (h + 3 - p[0]) % 3 == 1;
	}
	if(games[n][k][h] != -1){
		return games[n][k][h];
	}
	if(h == 0){
		games[n][k][h] = max(max(compute(games, p, n - 1, k, 0), compute(games, p, n - 1, k - 1, 1)), compute(games, p, n - 1, k - 1, 2));
	}else if(h == 1){
		games[n][k][h] = max(max(compute(games, p, n - 1, k - 1, 0), compute(games, p, n - 1, k, 1)), compute(games, p, n - 1, k - 1, 2));
	}else{
		games[n][k][h] = max(max(compute(games, p, n - 1, k - 1, 0), compute(games, p, n - 1, k - 1, 1)), compute(games, p, n - 1, k, 2));
	}
	if((h + 3 - p[n]) % 3 == 1){
		++games[n][k][h];
	}
	return games[n][k][h];
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int seq[100000];
	for(int i = 0; i < n; ++i){
		char x;
		scanf(" %c", &x);
		if(x == 'H'){
			seq[i] = 0;
		}else if(x == 'P'){
			seq[i] = 1;
		}else{
			seq[i] = 2;
		}
	}
	int games[100000][21][3];
	memset(games, -1, sizeof(games));
	printf("%d", max(max(compute(games, seq, n - 1, k, 0), compute(games, seq, n - 1, k, 1)), compute(games, seq, n - 1, k, 2)));
	return 0;
}
