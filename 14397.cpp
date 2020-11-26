#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[51][51];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int shore = 0;
	int dx[8] = {1, 0, 0, -1, 1, -1, 1, -1};
	int dy[8] = {0, 1, -1, 0, -1, -1, 1, 1};
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < m; ++y){
			for(int k = 0; k < 4; ++k){
				int nx = x + dx[k], ny = y + dy[k];
				if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != map[x][y]){
					++shore;
				}
			}
			if(x % 2 == 0){
				for(int k = 4; k < 6; ++k){
					int nx = x + dx[k], ny = y + dy[k];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != map[x][y]){
						++shore;
					}
				}
			}else{
				for(int k = 6; k < 8; ++k){
					int nx = x + dx[k], ny = y + dy[k];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != map[x][y]){
						++shore;
					}
				}
			}
		}
	}
	shore /= 2;
	printf("%d", shore);
	return 0;
}
