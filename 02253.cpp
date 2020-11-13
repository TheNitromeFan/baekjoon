#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int jumps[10001][300] = {};
	// jumps[x][y]: # of jumps when stepping on rock x at speed y
	for(int i = 0; i < m; ++i){
		int x;
		scanf("%d", &x);
		for(int j = 0; j < 300; ++j){
			jumps[x][j] = -1;
		}
	}
	jumps[2][1] = 1;
	for(int i = 2; i < n; ++i){
		for(int j = 1; j < 300; ++j){
			if(jumps[i][j] == 0){
				continue;
			}
			if(i + j + 1 <= n && j + 1 < 300 && jumps[i + j + 1][j + 1] != -1
			&& (jumps[i + j + 1][j + 1] == 0 || jumps[i + j + 1][j + 1] > jumps[i][j] + 1)){
				jumps[i + j + 1][j + 1] = jumps[i][j] + 1;
			}
			if(i + j <= n && jumps[i + j][j] != -1
			&& (jumps[i + j][j] == 0 || jumps[i + j][j] > jumps[i][j] + 1)){
				jumps[i + j][j] = jumps[i][j] + 1;
			}
			if(i + j - 1 <= n && j > 1 && jumps[i + j - 1][j - 1] != -1
			&& (jumps[i + j - 1][j - 1] == 0 || jumps[i + j - 1][j - 1] > jumps[i][j] + 1)){
				jumps[i + j - 1][j - 1] = jumps[i][j] + 1;
			}
		}
	}
	int minJumps = -1;
	for(int j = 0; j < 300; ++j){
		if(jumps[n][j] != 0 && (minJumps == -1 || jumps[n][j] < minJumps)){
			minJumps = jumps[n][j];
		}
	}
	printf("%d", minJumps);
	return 0;
}
