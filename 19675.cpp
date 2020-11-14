#include <cstdio>

bool correct(int b[][3]){
	for(int i = 0; i < 3; ++i){
		if(b[i][0] == b[i][1] || b[i][0] == b[i][2] || b[i][1] == b[i][2]){
			return false;
		}
	}
	for(int j = 0; j < 3; ++j){
		if(b[0][j] == b[1][j] || b[0][j] == b[2][j] || b[1][j] == b[2][j]){
			return false;
		}
	}
	return true;
}

void solve(int b[][3], int pos, int &sols){
	if(pos == 9){
		sols += correct(b);
		return;
	}
	int x = pos / 3, y = pos % 3;
	if(b[x][y] != 0){
		solve(b, pos + 1, sols);
		return;
	}
	for(int z = 1; z <= 9; ++z){
		b[x][y] = z;
		solve(b, pos + 1, sols);
		b[x][y] = 0;
	}
}

int main(){
	int b[3][3];
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			scanf("%d", &b[i][j]);
		}
	}
	int ans = 0;
	solve(b, 0, ans);
	printf("%d", ans);
	return 0;
}
