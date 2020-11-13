#include <cstdio>
#include <queue>

using namespace std;

int map[300][300];
int sub[300][300];
int visited[300][300];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int r, int c, int startx, int starty){
	queue<int> q;
	q.push(startx);
	q.push(starty);
	visited[startx][starty] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] != 0 && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int time = 0;
	while(true){
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				visited[i][j] = false;
			}
		}
		int component = 0;
		bool glacier_found = false;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				if(map[i][j] != 0 && !visited[i][j]){
					bfs(r, c, i, j);
					++component;
					glacier_found = true;
				}
			}
		}
		if(component >= 2){
			break;
		}else if(!glacier_found){
			printf("0");
			return 0;
		}
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				sub[i][j] = 0;
				if(map[i][j] != 0){
					for(int k = 0; k < 4; ++k){
						if(map[i+dx[k]][j+dy[k]] == 0 && sub[i][j] < map[i][j]){
							++sub[i][j];
						}
					}
				}
			}
		}
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				map[i][j] -= sub[i][j];
			}
		}
		++time;
	}
	printf("%d", time);
	return 0;
}
