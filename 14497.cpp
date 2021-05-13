#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#define MAX 301

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) > get<2>(b);
		}
};

int dijkstra(char map[][MAX], int n, int m, int sx, int sy, int fx, int fy){
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	bool visited[MAX][MAX] = {};
	dist[sx][sy] = 0;
	pq.push(make_tuple(sx, sy, 0));
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	while(!pq.empty()){
		tuple<int, int, int> t = pq.top();
		pq.pop();
		int x = get<0>(t), y = get<1>(t);
		if(x == fx && y == fy){
			return dist[x][y];
		}
		if(visited[x][y]){
			continue;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
				continue;
			}
			int cmp = dist[x][y];
			if(map[nx][ny] == '1'){
				++cmp;
			}
			if(dist[nx][ny] == -1 || dist[nx][ny] > cmp){
				dist[nx][ny] = cmp;
				pq.push(make_tuple(nx, ny, dist[nx][ny]));
			}
		}
		visited[x][y] = true;
 	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	--x1;
	--y1;
	--x2;
	--y2;
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < m; ++j){
			if(map[i][j] == '*'){
				map[i][j] = '0';
			}else if(map[i][j] == '#'){
				map[i][j] = '1';
			}
		}
	}
	printf("%d", dijkstra(map, n, m, x1, y1, x2, y2));
	return 0;
}
