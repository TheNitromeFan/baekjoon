#include <cstdio>
#include <queue>

using std::queue;

char map[51][51];

int water_time[51][51], hedgehog_time[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs_water(int r, int c, int startx, int starty){
	queue<int> q;
	bool visited[50][50] = {};
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
			if(nx >= 0 && nx < r && ny >= 0 && ny < c 
			&& map[nx][ny] != 'X' && map[nx][ny] != 'D'
			&& !visited[nx][ny]){
				if(water_time[nx][ny] == 0 || water_time[nx][ny] > water_time[x][y] + 1){
					water_time[nx][ny] = water_time[x][y] + 1;
					q.push(nx);
					q.push(ny);
				}
				visited[nx][ny] = true;
			}
		}
	}
}

int bfs_hedgehog(int r, int c, int startx, int starty){
	queue<int> q;
	bool visited[50][50] = {};
	q.push(startx);
	q.push(starty);
	visited[startx][starty] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		// printf("(%d %d) popped\n", x, y);
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c 
			&& map[nx][ny] != 'X' && map[nx][ny] != '*'
			&& !visited[nx][ny]){
				hedgehog_time[nx][ny] = hedgehog_time[x][y] + 1;
				if(map[nx][ny] == 'D'){
					return hedgehog_time[nx][ny];
				}
				if(water_time[nx][ny] == 0 || hedgehog_time[nx][ny] < water_time[nx][ny]){
					q.push(nx);
					q.push(ny);
					// printf("(%d %d) pushed\n", nx, ny);
				}
				visited[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	int waterx, watery, hedgehogx, hedgehogy;
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] == '*'){
				waterx = i;
				watery = j;
				bfs_water(r, c, waterx, watery);
			}else if(map[i][j] == 'S'){
				hedgehogx = i;
				hedgehogy = j;
			}
		}
	}
	/*
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%d ", water_time[i][j]);
		}
		printf("\n");
	}
	*/
	int ans = bfs_hedgehog(r, c, hedgehogx, hedgehogy);
	/*
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%d ", hedgehog_time[i][j]);
		}
		printf("\n");
	}
	*/
	if(ans == -1){
		printf("KAKTUS");
	}else{
		printf("%d", ans);
	}
	return 0;
}
