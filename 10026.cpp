#include <cstdio>
#include <cstring>
#define MAX (100 + 1)

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(char colors[][MAX], bool visited[][MAX], int n, int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n && colors[nx][ny] == colors[x][y] && !visited[nx][ny]){
			dfs(colors, visited, n, nx, ny);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	char colors[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", colors[i]);
	}
	int human = 0;
	bool visited[MAX][MAX];
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(!visited[i][j]){
				dfs(colors, visited, n, i, j);
				++human;
			}
		}
	}
	int cow = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(colors[i][j] == 'G'){
				colors[i][j] = 'R';
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(!visited[i][j]){
				dfs(colors, visited, n, i, j);
				++cow;
			}
		}
	}
	printf("%d %d", human, cow);
	return 0;
}
