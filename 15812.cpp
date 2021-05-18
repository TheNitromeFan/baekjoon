#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define MAX 22

using namespace std;

int devastate(char map[][MAX], int n, int m, int cnt, int x1, int y1, int x2, int y2,
	int dx[4], int dy[4]){
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	q.push(x1);
	q.push(y1);
	dist[x1][y1] = 0;
	q.push(x2);
	q.push(y2);
	dist[x2][y2] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(map[x][y] == '1'){
			--cnt;
			if(cnt == 0){
				return dist[x][y];
			}
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
	char map[MAX][MAX];
	vector<pair<int, int>> spaces;
	int village_cnt = 0;
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < m; ++j){
			if(map[i][j] == '0'){
				spaces.push_back(make_pair(i, j));
			}else{
				++village_cnt;
			}
		}
	}
	int ans = 400000;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for(unsigned i1 = 0; i1 < spaces.size(); ++i1){
		for(unsigned i2 = 0; i2 < i1; ++i2){
			pair<int, int> p1 = spaces[i1], p2 = spaces[i2];
			int cmp = devastate(map, n, m, village_cnt, p1.first, p1.second, p2.first, p2.second, dx, dy);
			if(ans > cmp){
				ans = cmp;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
