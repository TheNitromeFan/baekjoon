#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void traverse(vector<int> &post_order, vector<vector<int>> &adj, vector<bool> &visited, int a){
	if(visited[a]){
		return;
	}
	visited[a] = true;
	for(int b : adj[a]){
		traverse(post_order, adj, visited, b);
	}
	post_order.push_back(a);
}

void assign(vector<vector<int>> &rev, vector<int> &assigned, int b, int root){
	if(assigned[b] != -1){
		return;
	}
	assigned[b] = root;
	for(int a : rev[b]){
		assign(rev, assigned, a, root);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	vector<vector<int>> adj(2 * k + 1), rev(2 * k + 1);
	for(int i = 0; i < n; ++i){
		int l1, l2, l3;
		char c1, c2, c3;
		cin >> l1 >> c1 >> l2 >> c2 >> l3 >> c3;
		if(c1 == 'R'){
			l1 = 2 * k + 1 - l1;
		}
		if(c2 == 'R'){
			l2 = 2 * k + 1 - l2;
		}
		if(c3 == 'R'){
			l3 = 2 * k + 1 - l3;
		}
		adj[2 * k + 1 - l1].push_back(l2);
		rev[l2].push_back(2 * k + 1 - l1);
		adj[2 * k + 1 - l2].push_back(l1);
		rev[l1].push_back(2 * k + 1 - l2);
		adj[2 * k + 1 - l2].push_back(l3);
		rev[l3].push_back(2 * k + 1 - l2);
		adj[2 * k + 1 - l3].push_back(l2);
		rev[l2].push_back(2 * k + 1 - l3);
		adj[2 * k + 1 - l3].push_back(l1);
		rev[l1].push_back(2 * k + 1 - l3);
		adj[2 * k + 1 - l1].push_back(l3);
		rev[l3].push_back(2 * k + 1 - l1);
	}
	vector<bool> visited(2 * k + 1);
	vector<int> post_order;
	for(int a = 1; a <= 2 * k; ++a){
		traverse(post_order, adj, visited, a);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(2 * k + 1, -1);
	int comp = 0;
	for(int b : post_order){
		if(assigned[b] == -1){
			++comp;
			assign(rev, assigned, b, comp);
		}
	}
	vector<bool> truth(k + 1);
	for(int a = 1; a <= k; ++a){
		if(assigned[a] == assigned[2 * k + 1 - a]){
			cout << -1;
			return 0;
		}else if(assigned[a] > assigned[2 * k + 1 - a]){
			truth[a] = true;
		}
	}
	for(int a = 1; a <= k; ++a){
		cout << (truth[a] ? 'B' : 'R');
	}
	return 0;
}
