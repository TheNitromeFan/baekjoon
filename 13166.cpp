#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 810000

using namespace std;

int visited[MAX], assigned[MAX];

void traverse(vector<int> &post_order, vector<vector<int>> &adj, int a){
	if(visited[a]){
		return;
	}
	visited[a] = 1;
	for(int b : adj[a]){
		traverse(post_order, adj, b);
	}
	post_order.push_back(a);
}

void assign(vector<vector<int>> &rev, int b, int root){
	if(assigned[b] != -1){
		return;
	}
	assigned[b] = root;
	for(int a : rev[b]){
		assign(rev, a, root);
	}
}

bool satisfiable(vector<vector<int>> &adj, vector<vector<int>> &rev, int n){
	memset(visited, 0, sizeof(visited));
	vector<int> post_order;
	for(int a = 1; a <= 4 * n; ++a){
		traverse(post_order, adj, a);
	}
	reverse(post_order.begin(), post_order.end());
	memset(assigned, -1, sizeof(assigned));
	int comp = 0;
	for(int b : post_order){
		if(assigned[b] == -1){
			++comp;
			assign(rev, b, comp);
		}
	}
	for(int a = 1; a <= 2 * n; ++a){
		if(assigned[a] == assigned[4 * n + 1 - a]){
			return false;
		}
	}
	return true;
}

int bin_search(vector<pair<pair<int, int>, pair<int, int>>> &v, int n){
	int k = -1;
	int low = 0, high = 1000000;
	vector<vector<int>> adj(4 * n + 1), rev(4 * n + 1);
	vector<vector<int>> witness(2 * n + 1);
	for(int u = 1; u <= n; ++u){
		int x = 2 * u - 1, y = 2 * u;
		adj[4 * n + 1 - x].push_back(y);
		rev[y].push_back(4 * n + 1 - x);
		adj[4 * n + 1 - y].push_back(x);
		rev[x].push_back(4 * n + 1 - y);
		pair<int, int> p1 = v[u].first, p2 = v[u].second;
		int a = p1.first, b = p2.first;
		witness[a].push_back(x);
		witness[b].push_back(y);
	}
	for(int f = 1; f <= 2 * n; ++f){
		if(witness[f].size() == 2){
			int x = witness[f][0], y = witness[f][1];
			adj[x].push_back(4 * n + 1 - y);
			rev[4 * n + 1 - y].push_back(x);
			adj[y].push_back(4 * n + 1 - x);
			rev[4 * n + 1 - x].push_back(y);
		}
	}
	while(low <= high){
		int mid = (low + high) / 2;
		vector<vector<int>> adj1 = adj, rev1 = rev;
		for(int u = 1; u <= n; ++u){
			pair<int, int> p1 = v[u].first, p2 = v[u].second;
			int ka = p1.second, kb = p2.second;
			if(ka > mid){
				int x = 2 * u - 1;
				adj1[x].push_back(4 * n + 1 - x);
				rev1[4 * n + 1 - x].push_back(x);
			}
			if(kb > mid){
				int y = 2 * u;
				adj1[y].push_back(4 * n + 1 - y);
				rev1[4 * n + 1 - y].push_back(y);
			}
		}
		if(satisfiable(adj1, rev1, n)){
			k = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<pair<int, int>, pair<int, int>>> v(n + 1);
	for(int i = 1; i <= n; ++i){
		int a, ka, b, kb;
		cin >> a >> ka >> b >> kb;
		v[i] = make_pair(make_pair(a, ka), make_pair(b, kb));
	}
	cout << bin_search(v, n) << '\n';
	return 0;
}
