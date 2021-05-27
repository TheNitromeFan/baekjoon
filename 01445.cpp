#include <cstdio>
#include <cstring>
#include <vector>
#include <tuple>
#include <queue>
#define MAX 51

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) > get<2>(b);
		}
};

int trash(char map[][MAX], int n, int m, int dx[4], int dy[4], int x, int y){
	if(map[x][y] == 'g'){
		return 5000;
	}
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 'g'){
			return 1;
		}
	}
	return 0;
}

int dijkstra(int cost[][MAX], int n, int m, int dx[4], int dy[4], int sx, int sy, int fx, int fy){
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	bool visited[MAX][MAX] = {};
	dist[sx][sy] = 0;
	pq.push(make_tuple(sx, sy, 0));
	while(!pq.empty()){
		tuple<int, int, int> t = pq.top();
		pq.pop();
		int x = get<0>(t), y = get<1>(t);
		if(visited[x][y]){
			continue;
		}
		visited[x][y] = true;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
				continue;
			}
			if(nx == fx && ny == fy){
				return dist[x][y];
			}
			int w = cost[nx][ny];
			if(dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + w){
				dist[nx][ny] = dist[x][y] + w;
				pq.push(make_tuple(nx, ny, dist[nx][ny]));
			}
		}
	}
	return dist[fx][fy];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	int sx = -1, sy = -1, fx = -1, fy = -1;
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < m; ++j){
			if(map[i][j] == 'S'){
				sx = i;
				sy = j;
			}else if(map[i][j] == 'F'){
				fx = i;
				fy = j;
			}
		}
	}
	int cost[MAX][MAX] = {};
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cost[i][j] = trash(map, n, m, dx, dy, i, j);
		}
	}
	int ans = dijkstra(cost, n, m, dx, dy, sx, sy, fx, fy);
	printf("%d %d", ans / 5000, ans % 5000);
	return 0;
}
