#include <cstdio>
#include <queue>

using namespace std;

char map[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int max_travel(int travel[51][51], int n, int m){
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(travel[i][j] > ans){
				ans = travel[i][j];
			}
		}
	}
	return ans;
}

int bfs(int n, int m, int startx, int starty){
	int travel[51][51];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			travel[i][j] = -1;
		}
	}
	queue<int> q;
	q.push(startx);
	q.push(starty);
	travel[startx][starty] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int dir = 0; dir < 4; ++dir){
			int nx = x + dx[dir], ny = y + dy[dir];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m 
			&& map[nx][ny] == 'L' && travel[nx][ny] == -1){
				travel[nx][ny] = travel[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	return max_travel(travel, n, m);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] == 'L'){
				int cmp = bfs(n, m, i, j);
				if(cmp > ans){
					ans = cmp;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
