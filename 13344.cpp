#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, char, int> a, tuple<int, char, int> b){
	return get<1>(a) < get<1>(b);
}

int find_parent(vector<int> &parent, int x){
	if(parent[x] != x){
		parent[x] = find_parent(parent, parent[x]);
	}
	return parent[x];
}

void merge(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x), py = find_parent(parent, y);
	if(px != py){
		parent[px] = py;
	}
}

bool toposort(vector<tuple<int, char, int>> &matches, int n, int m){
	vector<int> parent(n);
	for(int j = 0; j < n; ++j){
		parent[j] = j;
	}
	sort(matches.begin(), matches.end(), cmp);
	int i;
	for(i = 0; i < m && get<1>(matches[i]) == '='; ++i){
		// cout << get<0>(matches[i]) << ' ' << get<1>(matches[i]) << ' ' << get<2>(matches[i]) << '\n';
		merge(parent, get<0>(matches[i]), get<2>(matches[i]));
	}
	queue<int> q;
	vector<vector<int>> adj(n);
	vector<int> indegree(n, 0);
	for(; i < m; ++i){
		int px = find_parent(parent, get<0>(matches[i])), py = find_parent(parent, get<2>(matches[i]));
		// cout << px << ' ' << py << '\n';
		adj[px].push_back(py);
		++indegree[py];
	}
	vector<bool> visited(n, false);
	int cnt = 0;
 	for(int j = 0; j < n; ++j){
		if(find_parent(parent, j) == j){
			++cnt;
			if(indegree[j] == 0){
				q.push(j);
			}
		}
	}
	while(!q.empty()){
		--cnt;
		int x = q.front();
		q.pop();
		for(int y : adj[x]){
			--indegree[y];
			if(indegree[y] == 0){
				q.push(y);
			}
		}
	}
	return cnt == 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, char, int>> matches(m);
	for(int i = 0; i < m; ++i){
		cin >> get<0>(matches[i]) >> get<1>(matches[i]) >> get<2>(matches[i]);
	}
	cout << (toposort(matches, n, m) ? "consistent" : "inconsistent");
	return 0;
}
