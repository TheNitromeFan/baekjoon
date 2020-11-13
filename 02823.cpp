#include <cstdio>
#define MAX (10 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool has_dead_end(char map[][MAX], int n, int m){
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < m; ++y){
			if(map[x][y] == 'X'){
				continue;
			}
			int open = 0;
			for(int i = 0; i < 4; ++i){
				int nx = x + dx[i], ny = y + dy[i];
				if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.'){
					++open;
				}
			}
			if(open <= 1){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char town[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", town[i]);
	}
	printf("%d", has_dead_end(town, r, c));
	return 0;
}
