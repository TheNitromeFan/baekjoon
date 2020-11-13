#include <cstdio>
#include <queue>
#define MAX 20

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int time(int a[][MAX], int n, int &startx, int &starty, int &sz, int &eaten){
	queue<int> q;
	int dist[MAX][MAX] = {};
	q.push(startx);
	q.push(starty);
	int min_dist = -1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n || (!(nx == startx && ny == starty) && dist[nx][ny] > 0) || a[nx][ny] > sz){
				continue;
			}
			dist[nx][ny] = dist[x][y] + 1;
			q.push(nx);
			q.push(ny);
			if(a[nx][ny] > 0 && a[nx][ny] < sz && min_dist == -1){
				min_dist = dist[nx][ny];
			}
		}
	}
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < n; ++y){
			if(a[x][y] > 0 && a[x][y] < sz && dist[x][y] == min_dist){
				a[x][y] = 0;
				startx = x;
				starty = y;
				++eaten;
				if(eaten == sz){
					++sz;
					eaten = 0;
				}
				return min_dist;
			}
		}
	}
	return -1;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX][MAX];
	int x = 0, y = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &a[i][j]);
			if(a[i][j] == 9){
				a[i][j] = 0;
				x = i;
				y = j;
			}
		}
	}
	int sz = 2, eaten = 0;
	int ans = 0;
	while(true){
		// printf("%d %d %d %d\n", x, y, sz, eaten);
		int trip = time(a, n, x, y, sz, eaten);
		if(trip == -1){
			break;
		}
		ans += trip;
	}
	printf("%d", ans);
	return 0;
}
