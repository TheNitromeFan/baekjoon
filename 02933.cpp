#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 101

using namespace std;

bool chuck(char map[][MAX], int c, int row, bool left){
	if(left){
		for(int j = 0; j < c; ++j){
			if(map[row][j] == 'x'){
				map[row][j] = '.';
				return true;
			}
		}
	}else{
		for(int j = c - 1; j >= 0; --j){
			if(map[row][j] == 'x'){
				map[row][j] = '.';
				return true;
			}
		}
	}
	return false;
}

int bfs(char map[][MAX], bool visited[][MAX], int r, int c, int dx[4], int dy[4]){
	queue<int> q;
	int cnt = 0;
	for(int j = 0; j < c; ++j){
		if(map[r - 1][j] == 'x'){
			q.push(r - 1);
			q.push(j);
			visited[r - 1][j] = true;
			++cnt;
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == 'x' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
				++cnt;
			}
		}
	}
	return cnt;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	bool visited[MAX][MAX] = {};
	int cnt = bfs(map, visited, r, c, dx, dy);
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		int h;
		scanf("%d", &h);
		if(chuck(map, c, r - h, a0 % 2 == 0)){
			--cnt;
		}
		memset(visited, false, sizeof(visited));
		int cnt1 = bfs(map, visited, r, c, dx, dy);
		if(cnt > cnt1){
			int fall_distance = MAX * MAX;
			for(int j = 0; j < c; ++j){
				int row = r;
				for(int i = r - 1; i >= 0; --i){
					if(map[i][j] == 'x' && visited[i][j]){
						row = i;
					}else if(map[i][j] == 'x'){
						fall_distance = min(fall_distance, row - i - 1);
						// printf("%d %d %d %d\n", row, i, j, fall_distance);
					}
				}
			}
			for(int i = r - 1; i >= 0; --i){
				for(int j = 0; j < c; ++j){
					if(map[i][j] == 'x' && !visited[i][j]){
						swap(map[i][j], map[i + fall_distance][j]);
					}
				}
			}
		}
		/*
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		printf("%d %d\n", cnt, cnt1);
		*/
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
