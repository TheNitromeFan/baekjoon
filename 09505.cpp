#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <unordered_map>
#define MAX 1001
#define MAXVAL 1000000000

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) > get<2>(b);
		}
};

int dijkstra(int time[][MAX], int h, int w, int sx, int sy){
	int dist[MAX][MAX];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			dist[i][j] = MAXVAL;
		}
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	bool visited[MAX][MAX] = {};
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
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
			if(!(nx >= 0 && nx < h && ny >= 0 && ny < w)){
				return dist[x][y];
			}
			if(dist[nx][ny] > dist[x][y] + time[nx][ny]){
				dist[nx][ny] = dist[x][y] + time[nx][ny];
				pq.push(make_tuple(nx, ny, dist[nx][ny]));
			}
		}
	}
	return -1;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int k, w, h;
		scanf("%d %d %d", &k, &w, &h);
		unordered_map<char, int> fight({{'E', 0}});
		for(int a1 = 0; a1 < k; ++a1){
			char c;
			int val;
			scanf(" %c %d", &c, &val);
			fight[c] = val;
		}
		char map[MAX][MAX];
		int time[MAX][MAX];
		int sx = -1, sy = -1;
		for(int i = 0; i < h; ++i){
			scanf("%s", map[i]);
			for(int j = 0; j < w; ++j){
				time[i][j] = fight[map[i][j]];
				if(map[i][j] == 'E'){
					sx = i;
					sy = j;
				}
			}
		}
		printf("%d\n", dijkstra(time, h, w, sx, sy));
	}
	return 0;
}
