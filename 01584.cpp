#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 501

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) > get<2>(b);
		}
};

int dijkstra(int map[][MAX]){
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	bool visited[MAX][MAX] = {};
	dist[0][0] = 0;
	pq.push(make_tuple(0, 0, 0));
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while(!pq.empty()){
		tuple<int, int, int> t = pq.top();
		pq.pop();
		int x = get<0>(t), y = get<1>(t);
		// cout << x << ' ' << y << '\n';
		if(x == MAX - 1 && y == MAX - 1){
			break;
		}else if(visited[x][y]){
			continue;
		}
		visited[x][y] = true;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX)){
				continue;
			}
			if(map[nx][ny] == 0 && (dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y])){
				dist[nx][ny] = dist[x][y];
				pq.push(make_tuple(nx, ny, dist[nx][ny]));
			}else if(map[nx][ny] == 1 && (dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + 1)){
				dist[nx][ny] = dist[x][y] + 1;
				pq.push(make_tuple(nx, ny, dist[nx][ny]));
			}
		}
	}
	return dist[MAX - 1][MAX - 1];
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int n, m;
	cin >> n;
	int map[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2){
			swap(x1, x2);
		}
		if(y1 > y2){
			swap(y1, y2);
		}
		for(int x = x1; x <= x2; ++x){
			for(int y = y1; y <= y2; ++y){
				map[x][y] = 1;
			}
		}
	}
	cin >> m;
	for(int j = 0; j < m; ++j){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2){
			swap(x1, x2);
		}
		if(y1 > y2){
			swap(y1, y2);
		}
		for(int x = x1; x <= x2; ++x){
			for(int y = y1; y <= y2; ++y){
				map[x][y] = 2;
			}
		}
	}
	cout << dijkstra(map);
	return 0;
}
