#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool connected(vector<int> &amt, vector<vector<int>> &adj, vector<int> &vec, int n, int &sum){
	if(vec.empty()){
		return false;
	}
	queue<int> q;
	vector<bool> visited(n + 1);
	unsigned cnt = 0;
	int start = vec[0];
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++cnt;
		sum += amt[u];
		for(int v : adj[u]){
			if(!visited[v]){
				if(find(vec.begin(), vec.end(), v) != vec.end()){
					q.push(v);
				}
				visited[v] = true;
			}
		}
	}
	return cnt == vec.size();
}

int minimum_difference(vector<int> &amt, vector<vector<int>> &adj, int n){
	int ret = 1000000000;
	for(int m = 0; m < (1 << n); ++m){
		vector<int> vec1, vec2;
		int k = m;
		for(int i = 1; i <= n; ++i){
			if(k % 2 == 1){
				vec1.push_back(i);
			}else{
				vec2.push_back(i);
			}
			k /= 2;
		}
		int sum1 = 0, sum2 = 0;
		bool conn1 = connected(amt, adj, vec1, n, sum1);
		bool conn2 = connected(amt, adj, vec2, n, sum2);
		if(conn1 && conn2 && ret > abs(sum1 - sum2)){
			ret = abs(sum1 - sum2);
		}
	}
	return (ret < 1000000000) ? ret : -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; ++i){
		int m;
		cin >> m;
		adj[i].resize(m);
		for(int j = 0; j < m; ++j){
			cin >> adj[i][j];
		}
	}
	cout << minimum_difference(a, adj, n);
	return 0;
}
