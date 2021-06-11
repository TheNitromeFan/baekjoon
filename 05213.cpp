#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAXN 501

using namespace std;

int tile_number(int n, int x, int y){
	if(x % 2 == 1){
		return (2 * n - 1) * (x - 1) / 2 + y;
	}else{
		return (2 * n - 1) * (x - 2) / 2 + n + y;
	}
}

pair<int, int> coordinates(int n, int t){
	--t;
	int x = -1, y = -1;
	if(t % (2 * n - 1) < n){
		x = t / (2 * n - 1) * 2 + 1;
		y = t % (2 * n - 1) + 1;
	}else{
		x = t / (2 * n - 1) * 2 + 2;
		y = t % (2 * n - 1) - n + 1;
	}
	return make_pair(x, y);
}

int bfs(pair<int, int> map[][MAXN], int n, int prev[MAXN * MAXN]){
	int dist[MAXN * MAXN];
	queue<int> tiles;
	bool visited[MAXN][MAXN] = {};
	dist[1] = 0;
	tiles.push(1);
	visited[1][1] = true;
	int ret = 1;
	while(!tiles.empty()){
		int t = tiles.front();
		tiles.pop();
		if(ret < t){
			ret = t;
		}
		pair<int, int> p = coordinates(n, t);
		int x = p.first, y = p.second;
		if(y > 1 && map[x][y - 1].second == map[x][y].first && !visited[x][y - 1]){
			int nt = tile_number(n, x, y - 1);
			dist[nt] = dist[t] + 1;
			tiles.push(nt);
			visited[x][y - 1] = true;
			prev[nt] = t;
		}
		if(((x % 2 == 1 && y < n) || (x % 2 == 0 && y < n - 1)) && map[x][y + 1].first == map[x][y].second && !visited[x][y + 1]){
			int nt = tile_number(n, x, y + 1);
			dist[nt] = dist[t] + 1;
			tiles.push(nt);
			visited[x][y + 1] = true;
			prev[nt] = t;
		}
		if(x % 2 == 1){
			if(x > 1 && y > 1 && map[x - 1][y - 1].second == map[x][y].first && !visited[x - 1][y - 1]){
				int nt = tile_number(n, x - 1, y - 1);
				dist[nt] = dist[t] + 1;
				tiles.push(nt);
				visited[x - 1][y - 1] = true;
				prev[nt] = t;
			}
			if(x > 1 && y < n && map[x - 1][y].first == map[x][y].second && !visited[x - 1][y]){
				int nt = tile_number(n, x - 1, y);
				dist[nt] = dist[t] + 1;
				tiles.push(nt);
				visited[x - 1][y] = true;
				prev[nt] = t;
			}
			if(x < n && y > 1 && map[x + 1][y - 1].second == map[x][y].first && !visited[x + 1][y - 1]){
				int nt = tile_number(n, x + 1, y - 1);
				dist[nt] = dist[t] + 1;
				tiles.push(nt);
				visited[x + 1][y - 1] = true;
				prev[nt] = t;
			}
			if(x < n && y < n && map[x + 1][y].first == map[x][y].second && !visited[x + 1][y]){
				int nt = tile_number(n, x + 1, y);
				dist[nt] = dist[t] + 1;
				tiles.push(nt);
				visited[x + 1][y] = true;
				prev[nt] = t;
			}
		}else{
			if(x > 1 && map[x - 1][y].second == map[x][y].first && !visited[x - 1][y]){
				int nt = tile_number(n, x - 1, y);
				dist[nt] = dist[t] + 1;
				tiles.push(nt);
				visited[x - 1][y] = true;
				prev[nt] = t;
			}
			if(x > 1 && map[x - 1][y + 1].first == map[x][y].second && !visited[x - 1][y + 1]){
				int nt = tile_number(n, x - 1, y + 1);
				dist[nt] = dist[t] + 1;
				tiles.push(nt);
				visited[x - 1][y + 1] = true;
				prev[nt] = t;
			}
			if(x < n && map[x + 1][y].second == map[x][y].first && !visited[x + 1][y]){
				int nt = tile_number(n, x + 1, y);
				dist[nt] = dist[t] + 1;
				tiles.push(nt);
				visited[x + 1][y] = true;
				prev[nt] = t;
			}
			if(x < n && map[x + 1][y + 1].first == map[x][y].second && !visited[x + 1][y + 1]){
				int nt = tile_number(n, x + 1, y + 1);
				dist[nt] = dist[t] + 1;
				tiles.push(nt);
				visited[x + 1][y + 1] = true;
				prev[nt] = t;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	pair<int, int> map[MAXN][MAXN];
	for(int i = 1; i <= n; ++i){
		int tiles = n;
		if(i % 2 == 0){
			tiles = n - 1;
		}
		for(int j = 1; j <= tiles; ++j){
			cin >> map[i][j].first >> map[i][j].second;
		}
	}
	int prev[MAXN * MAXN];
	memset(prev, -1, sizeof(prev));
	int end = bfs(map, n, prev);
	vector<int> ans = {end};
	while(ans.back() != 1){
		ans.push_back(prev[ans.back()]);
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int x : ans){
		cout << x << ' ';
	}
	return 0;
}
