#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#define MAX 10

using namespace std;

void bfs(int map[MAX][MAX], bool visited[MAX][MAX], int component_map[MAX][MAX], int n, int m, int sx, int sy, int dx[4], int dy[4], int label){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	component_map[sx][sy] = label;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
				component_map[nx][ny] = label;
			}
		}
	}
}

void update_adj(int component_map[MAX][MAX], int adj_mat[MAX][MAX], int n, int m, int sx, int sy, int dx[4], int dy[4]){
	int current_component = component_map[sx][sy];
	for(int i = 0; i < 4; ++i){
		int nx = sx;
		int ny = sy;
		int dist = 0;
		while(true){
			nx += dx[i];
			ny += dy[i];
			++dist;
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
				break;
			}
			int new_component = component_map[nx][ny];
			if(new_component == current_component){
				break;
			}else if(new_component != 0 && dist <= 2){
				break;
			}else if(new_component != 0){
				adj_mat[current_component][new_component] = min(adj_mat[current_component][new_component], dist - 1);
				break;
			}
		}
	}
}

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x);
	int py = find_parent(parent, y);
	parent[py] = px;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> map[i][j];
		}
	}
	int components = 0;
	int component_map[MAX][MAX] = {};
	bool visited[MAX][MAX] = {};
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] && !visited[i][j]){
				++components;
				bfs(map, visited, component_map, n, m, i, j, dx, dy, components);
			}
		}
	}
	int adj_mat[MAX][MAX];
	for(int i = 1; i <= components; ++i){
		for(int j = 1; j <= components; ++j){
			adj_mat[i][j] = MAX * MAX;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(component_map[i][j] != 0){
				update_adj(component_map, adj_mat, n, m, i, j, dx, dy);
			}
		}
	}
	vector<tuple<int, int, int>> edges;
	for(int i = 1; i <= components; ++i){
		for(int j = 1; j < i; ++j){
			if(adj_mat[i][j] != MAX * MAX){
				edges.push_back(make_tuple(i, j, adj_mat[i][j]));
			}
		}
	}
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
		return get<2>(a) < get<2>(b);
	});
	vector<int> parent(components + 1);
	for(int u = 1; u <= components; ++u){
		parent[u] = u;
	}
	int edge_count = 0;
	int weight = 0;
	for(tuple<int, int, int> edge : edges){
		int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			// cout << u << ' ' << v << ' ' << w << '\n';
			unite(parent, u, v);
			++edge_count;
			weight += w;
			if(edge_count == components - 1){
				break;
			}
		}
	}
	cout << (edge_count == components - 1 ? weight : -1);
	return 0;
}
