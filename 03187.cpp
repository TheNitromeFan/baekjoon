#include <cstdio>
#include <queue>
#define MAX (250 + 1)

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(char yard[][MAX], bool visited[][MAX], int r, int c, int sx, int sy, int &sheep, int &wolves){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	int scnt = 0, wcnt = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		switch(yard[x][y]){
			case 'k':
				++scnt;
				break;
			case 'v':
				++wcnt;
				break;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && yard[nx][ny] != '#' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	if(scnt > wcnt){
		wolves -= wcnt;
	}else{
		sheep -= scnt;
	}
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char yard[MAX][MAX];
	int sheep = 0, wolves = 0;
	for(int i = 0; i < r; ++i){
		scanf("%s", yard[i]);
		for(int j = 0; j < c; ++j){
			switch(yard[i][j]){
				case 'k':
					++sheep;
					break;
				case 'v':
					++wolves;
					break;
			}
		}
	}
	bool visited[MAX][MAX] = {};
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if((yard[i][j] == 'o' || yard[i][j] == 'v') && !visited[i][j]){
				bfs(yard, visited, r, c, i, j, sheep, wolves);
			}
		}
	}
	printf("%d %d", sheep, wolves);
	return 0;
}
