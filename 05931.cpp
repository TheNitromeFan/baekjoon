#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 55

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void mark_spot(int number[][MAX], char spots[][MAX], int n, int m, int label, int sx, int sy){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	number[sx][sy] = label;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && spots[nx][ny] == 'X' && number[nx][ny] == 0){
				q.push(nx);
				q.push(ny);
				number[nx][ny] = label;
			}
		}
	}
}

int find_path(int number[][MAX], int n, int m, queue<int> &q, int dist[][MAX]){
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(number[x][y] == 2){
			return dist[x][y] - 1;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char spots[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", spots[i]);
	}
	int number[MAX][MAX] = {};
	int label = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(spots[i][j] == 'X' && number[i][j] == 0){
				mark_spot(number, spots, n, m, label, i, j);
				++label;
			}
		}
	}
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(number[i][j] == 1){
				q.push(i);
				q.push(j);
				dist[i][j] = 0;
			}
		}
	}
	printf("%d", find_path(number, n, m, q, dist));
	return 0;
}
