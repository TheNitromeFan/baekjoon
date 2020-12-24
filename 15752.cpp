#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void visit(vector<vector<int>> &adj, int n, int start, vector<bool> &visited){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

int balls(vector<int> &v, int n){
	if(n == 1){
		return 1;
	}
	vector<vector<int>> adj(n);
	vector<int> indegree(n);
	for(int i = 0; i < n; ++i){
		if(i == 0){
			++indegree[1];
			adj[0].push_back(1);
		}else if(i == n - 1){
			++indegree[n - 2];
			adj[n - 1].push_back(n - 2);
		}else if(v[i] - v[i - 1] <= v[i + 1] - v[i]){
			++indegree[i - 1];
			adj[i].push_back(i - 1);
		}else{
			++indegree[i + 1];
			adj[i].push_back(i + 1);
		}
	}
	vector<int> vertex(n);
	for(int i = 0; i < n; ++i){
		vertex[i] = i;
	}
	sort(vertex.begin(), vertex.end(), [&indegree](int i, int j){
		return indegree[i] < indegree[j];
	});
	vector<bool> visited(n);
	int ret = 0;
	for(int u : vertex){
		if(!visited[u]){
			++ret;
			visit(adj, n, u, visited);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << balls(v, n);
	return 0;
}
