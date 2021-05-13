#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 2223

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) > get<2>(b);
		}
};

int dijkstra(int a[][MAX], int n){
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	bool visited[MAX][MAX] = {};
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	dist[1][1] = 0;
	pq.push(make_tuple(1, 1, 0));
	int dx[3] = {1, 0};
	int dy[3] = {0, 1};
	while(!pq.empty()){
		tuple<int, int, int> t = pq.top();
		pq.pop();
		int x = get<0>(t), y = get<1>(t);
		if(x == n && y == n){
			return dist[n][n];
		}else if(visited[x][y]){
			continue;
		}
		for(int i = 0; i < 2; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n){
				int d = max(0, a[nx][ny] - a[x][y] + 1);
				if(dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + d){
					// cout << x << ' ' << y << " -> " << nx << ' ' << ny << " : " << d << '\n';
					dist[nx][ny] = dist[x][y] + d;
					pq.push(make_tuple(nx, ny, dist[nx][ny]));
				}
			}
		}
		visited[x][y] = true;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	cout << dijkstra(a, n);
	return 0;
}
