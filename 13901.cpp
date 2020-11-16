#include <cstdio>
#define MAX 1000

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	bool map[MAX][MAX] = {};
	int k;
	scanf("%d", &k);
	for(int b = 0; b < k; ++b){
		int br, bc;
		scanf("%d %d", &br, &bc);
		map[br][bc] = true;
	}
	int x, y;
	scanf("%d %d", &x, &y);
	int dir[4];
	for(int i = 0; i < 4; ++i){
		scanf("%d", &dir[i]);
	}
	int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
	int index = 0;
	while(true){
		map[x][y] = true;
		int nx = x + dx[dir[index]], ny = y + dy[dir[index]];
		if(nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny]){
			int new_index = (index + 1) % 4;
			while(true){
				nx = x + dx[dir[new_index]];
				ny = y + dy[dir[new_index]];
				if(nx >= 0 && nx < r && ny >= 0 && ny < c && !map[nx][ny]){
					index = new_index;
					break;
				}
				new_index = (new_index + 1) % 4;
				if(new_index == index){
					printf("%d %d", x, y);
					return 0;
				}
			}
		}
		x = nx;
		y = ny;
	}
	return 0;
}
