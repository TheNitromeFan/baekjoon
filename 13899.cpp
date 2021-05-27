#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

bool backtrack(vector<vector<pair<int, int>>> &adj, vector<long long> &x, vector<bool> &visited, int n, int u, int cnt){
	for(pair<int, int> p : adj[u]){
		int v = p.first, dist = p.second;
		if(visited[v] && llabs(x[u] - x[v]) != dist){
			return false;
		}else if(!visited[v]){
			visited[v] = true;
			x[v] = x[u] + dist;
			if(backtrack(adj, x, visited, n, v, cnt + 1)){
				return true;
			}
			x[v] = x[u] - dist;
			if(backtrack(adj, x, visited, n, v, cnt + 1)){
				return true;
			}
			visited[v] = false;
			return false;
		}
	}
	if(cnt == n){
		return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adjx(n + 1), adjy(n + 1);
	for(int i = 0; i < m; ++i){
		int a, b, dx, dy;
		cin >> a >> b >> dx >> dy;
		adjx[a].push_back(make_pair(b, dx));
		adjx[b].push_back(make_pair(a, dx));
		adjy[a].push_back(make_pair(b, dy));
		adjy[b].push_back(make_pair(a, dy));
	}
	vector<long long> x(n + 1), y(n + 1);
	vector<bool> visitedx(n + 1), visitedy(n + 1);
	x[1] = 0;
	y[1] = 0;
	visitedx[1] = true;
	visitedy[1] = true;
	backtrack(adjx, x, visitedx, n, 1, 1);
	backtrack(adjy, y, visitedy, n, 1, 1);
	long long max_x = *max_element(x.begin(), x.end()), min_x = *min_element(x.begin(), x.end());
	if(max_x >= 1000000000){
		for(long long &xval : x){
			xval -= (max_x - 999999999);
		}
	}else if(min_x <= -1000000000){
		for(long long &xval : x){
			xval -= (min_x + 999999999);
		}
	}
	long long max_y = *max_element(y.begin(), y.end()), min_y = *min_element(y.begin(), y.end());
	if(max_y >= 1000000000){
		for(long long &yval : y){
			yval -= (max_y - 999999999);
		}
	}else if(min_y <= -1000000000){
		for(long long &yval : y){
			yval -= (min_y + 999999999);
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << x[i] << ' ' << y[i] << '\n';
	}
	return 0;
}
