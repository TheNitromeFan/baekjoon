#include <cstdio>
#include <queue>
#define MAX 200

using namespace std;

void nearest_white(queue<int> &q, char map[][MAX], int n, int m, int dist[][MAX]){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char bitmap[MAX][MAX];
	queue<int> q;
	int dist[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		scanf("%s", bitmap[i]);
		for(int j = 0; j < m; ++j){
			if(bitmap[i][j] == '0'){
				dist[i][j] = -1;
			}else{
				q.push(i);
				q.push(j);
			}
		}
	}
	nearest_white(q, bitmap, n, m, dist);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
