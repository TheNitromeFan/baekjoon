#include <cstdio>

using namespace std;

bool inbounds(int x, int y){
	return (x >= 2 && x <= 4) || (y >= 2 && y <= 4);
}

int main(){
	char board[7][9];
	for(int i = 0; i < 7; ++i){
		fgets(board[i], 9, stdin);
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	int cnt = 0;
	for(int x = 0; x < 7; ++x){
		for(int y = 0; y < 7; ++y){
			if(!(inbounds(x, y) && board[x][y] == 'o')){
				continue;
			}
			for(int k = 0; k < 4; ++k){
				int nx = x + dx[k];
				int ny = y + dy[k];
				int nnx = nx + dx[k];
				int nny = ny + dy[k];
				if(inbounds(nnx, nny) && board[nx][ny] == 'o' && board[nnx][nny] == '.'){
					++cnt;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
