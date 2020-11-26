#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	int dx[4] = {1, 0, 0, -1};
	int dy[4] = {0, 1, -1, 0};
	for(int a0 = 0; a0 < t; ++a0){
		int r, c;
		scanf("%d %d", &r, &c);
		char solid[51][51];
		for(int i = 0; i < r; ++i){
			scanf("%s", solid[i]);
		}
		int area = 0;
		for(int x = 0; x < r; ++x){
			for(int y = 0; y < c; ++y){
				int height = solid[x][y] - '0';
				if(height != 0){
					area += 2;
				}
				for(int k = 0; k < 4; ++k){
					int nx = x + dx[k], ny = y + dy[k];
					if(nx < 0 || nx >= r || ny < 0 || ny >= c){
						area += height;
					}else if(height > solid[nx][ny] - '0'){
						area += height - (solid[nx][ny] - '0');
					}
				}
			}
		}
		printf("%d\n", area);
	}
	return 0;
}
