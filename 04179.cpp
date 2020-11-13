#include <cstdio>
#include <queue>
#define MAX 1000

using std::queue;

char map[MAX+1][MAX+1];

int fire_time[MAX+1][MAX+1], escape_time[MAX+1][MAX+1];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs_fire(queue<int> &q, int r, int c){
	bool visited[MAX+1][MAX+1] = {};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		visited[x][y] = true;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] != '#' && !visited[nx][ny]){
				if(fire_time[nx][ny] == 0 || fire_time[nx][ny] > fire_time[x][y] + 1){
					fire_time[nx][ny] = fire_time[x][y] + 1;
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
}

int bfs_escape(int r, int c, int startx, int starty){
	queue<int> q;
	bool visited[MAX+1][MAX+1] = {};
	q.push(startx);
	q.push(starty);
	visited[startx][starty] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c){
				return escape_time[x][y] + 1;
			}
			if(map[nx][ny] != '#' && map[nx][ny] != 'F' && !visited[nx][ny]){
				escape_time[nx][ny] = escape_time[x][y] + 1;
				if(fire_time[nx][ny] == 0 || escape_time[nx][ny] < fire_time[nx][ny]){
					q.push(nx);
					q.push(ny);
				}
				visited[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main(){
	int w, h;
	scanf("%d %d", &w, &h);
	for(int i = 0; i < w; ++i){
		for(int j = 0; j < h; ++j){
			fire_time[i][j] = 0;
			escape_time[i][j] = 0;
		}
	}
	int startx = 0, starty = 0;
	for(int i = 0; i < w; ++i){
		scanf("%s", map[i]);
	}
	queue<int> q;
	for(int i = 0; i < w; ++i){
		for(int j = 0; j < h; ++j){
			if(map[i][j] == 'F'){
				q.push(i);
				q.push(j);
			}else if(map[i][j] == 'J'){
				startx = i;
				starty = j;
			}
		}
	}
	bfs_fire(q, w, h);
	int ans = bfs_escape(w, h, startx, starty);
	if(ans == -1){
		printf("IMPOSSIBLE\n");
	}else{
		printf("%d\n", ans);
	}
	return 0;
}
