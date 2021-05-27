#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include <queue>
#define MAX 1001

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) > get<2>(b);
		}
};

int dijkstra(int map[][MAX], int n, int m){
	if(map[1][1] == -1){
		return -1;
	}
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	bool visited[MAX][MAX] = {};
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	dist[1][1] = map[1][1];
	pq.push(make_tuple(1, 1, dist[1][1]));
	while(!pq.empty()){
		tuple<int, int, int> t = pq.top();
		pq.pop();
		int x = get<0>(t), y = get<1>(t);
		if(x == n && y == m){
			return dist[n][m];
		}
		if(visited[x][y]){
			continue;
		}
		visited[x][y] = true;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] != -1 && (dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + map[nx][ny])){
				dist[nx][ny] = dist[x][y] + map[nx][ny];
				pq.push(make_tuple(nx, ny, dist[nx][ny]));
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int map[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> map[i][j];
		}
	}
	cout << dijkstra(map, n, m);
	return 0;
}
