#include <iostream>
#define MAX 1000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int nrows, ncolumns;
	cin >> nrows >> ncolumns;
	int map[MAX][MAX] = {};
	for(int i = 0; i < nrows; ++i){
		for(int j = 0; j < ncolumns; ++j){
			cin >> map[i][j];
		}
	}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int ddx[4] = {1, 1, -1, -1};
	int ddy[4] = {-1, 1, 1, -1};
	int cardinal = 0, intercardinal = 0;
	for(int x = 0; x < nrows; ++x){
		for(int y = 0; y < ncolumns; ++y){
			if(!map[x][y]){
				continue;
			}
			for(int k = 0; k < 4; ++k){
				int nx = x + dx[k], ny = y + dy[k];
				if(nx >= 0 && nx < nrows && ny >= 0 && ny < ncolumns && map[nx][ny]){
					++cardinal;
					++intercardinal;
				}
				int nnx = x + ddx[k], nny = y + ddy[k];
				if(nnx >= 0 && nnx < nrows && nny >= 0 && nny < ncolumns && map[nnx][nny]){
					++intercardinal;
				}
			}
		}
	}
	cout << cardinal / 2 << ' ' << intercardinal / 2;
	return 0;
}
