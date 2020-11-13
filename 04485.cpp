#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#define MAX (125 + 1)

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/*
class Cmp{
	public:
		bool operator() (tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) < get<2>(b);
		}
};
*/

int dijkstra(int map[][MAX], int sz){
	queue<tuple<int, int, int>> pq;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	dist[0][0] = map[0][0];
	pq.push(make_tuple(0, 0, dist[0][0]));
	while(!pq.empty()){
		auto tmp = pq.front();
		pq.pop();
		int x = get<0>(tmp), y = get<1>(tmp);
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < sz && ny >= 0 && ny < sz && (dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + map[nx][ny])){
				dist[nx][ny] = dist[x][y] + map[nx][ny];
				pq.push(make_tuple(nx, ny, dist[nx][ny]));
			}
		}
	}
	return dist[sz - 1][sz - 1];
}

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int map[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		printf("Problem %d: %d\n", cnt, dijkstra(map, n));
	}
	return 0;
}
