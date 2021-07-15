#include <cstdio>
#include <queue>
#define MAX 50

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		char map[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", map[i]);
		}
		queue<int> q;
		bool visited[MAX][MAX] = {};
		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		if(map[0][0] == 'O'){
			q.push(0);
			q.push(0);
			visited[0][0] = true;
		}
		while(!q.empty()){
			int x = q.front();
			q.pop();
			int y = q.front();
			q.pop();
			for(int i = 0; i < 4; ++i){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 'O' && !visited[nx][ny]){
					q.push(nx);
					q.push(ny);
					visited[nx][ny] = true;
				}
			}
		}
		printf("Case: %d\n", a0);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				printf("+---");
			}
			printf("+\n");
			for(int j = 0; j < m; ++j){
				if(map[i][j] == 'X'){
					printf("| X ");
				}else if(visited[i][j]){
					printf("| M ");
				}else{
					printf("|   ");
				}
			}
			printf("|\n");
		}
		for(int j = 0; j < m; ++j){
			printf("+---");
		}
		printf("+\n");
		if(visited[n - 1][m - 1]){
			printf("Minions can cross the room \n");
		}else{
			printf("Minions cannot cross the room \n");
		}
	}
	return 0;
}
