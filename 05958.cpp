#include <cstdio>
#define MAX 1001

using namespace std;

void traverse(char space[][MAX], bool visited[][MAX], int n, int x, int y){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	visited[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n && space[nx][ny] == '*' && !visited[nx][ny]){
			traverse(space, visited, n, nx, ny);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	char space[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", space[i]);
	}
	bool visited[MAX][MAX] = {};
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(space[i][j] == '*' && !visited[i][j]){
				++cnt;
				traverse(space, visited, n, i, j);
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
