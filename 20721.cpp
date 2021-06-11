#include <cstdio>

using namespace std;

int main(){
	char board[8][9];
	for(int i = 0; i < 8; ++i){
		scanf("%s", board[i]);
	}
	bool unsafe[8][8] = {};
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	for(int x = 0; x < 8; ++x){
		for(int y = 0; y < 8; ++y){
			if(board[x][y] == 'R'){
				unsafe[x][y] = true;
				for(int k = 0; k < 4; ++k){
					int nx = x, ny = y;
					while(nx >= 0 && nx < 8 && ny >= 0 && ny < 8){
						unsafe[nx][ny] = true;
						nx += dx[k];
						ny += dy[k];
					}
				}
			}
		}
	}
	int cnt = 0;
	for(int x = 0; x < 8; ++x){
		for(int y = 0; y < 8; ++y){
			if(!unsafe[x][y]){
				++cnt;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
