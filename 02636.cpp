#include <cstdio>
#include <queue>

using namespace std;

int map[101][101];
bool melted[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int r, int c, int startx, int starty){
	queue<int> q;
	q.push(startx);
	q.push(starty);
	bool visited[101][101] = {};
	visited[startx][starty] = true;
	int cnt = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c){
				continue;
			}
			if(map[nx][ny] == 0 && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}else if(map[nx][ny] == 1){
				melted[nx][ny] = true;
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
	int time = 0, ans;
	bool clear = false;
	while(!clear){
		bfs(r, c, 0, 0);
		ans = 0;
		clear = true;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				if(map[i][j] == 1 && melted[i][j]){
					++ans;
					map[i][j] = 0;
				}else if(map[i][j] == 1){
					clear = false;
				}
			}
		}
		++time;
	}
	printf("%d\n%d", time, ans);
	return 0;
}
