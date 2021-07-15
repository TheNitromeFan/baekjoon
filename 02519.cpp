#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	int x1 = p1.first, y1 = p1.second;
	int x2 = p2.first, y2 = p2.second;
	int x3 = p3.first, y3 = p3.second;
	int cmp = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

bool intersect(pair<pair<int, int>, pair<int, int>> line1, pair<pair<int, int>, pair<int, int>> line2){
	pair<int, int> p1 = line1.first, p2 = line1.second;
	pair<int, int> p3 = line2.first, p4 = line2.second;
	return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

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
	int n;
	cin >> n;
	vector<pair<pair<int, int>, pair<int, int>>> line(3 * n + 1);
	for(int i = 1; i <= 3 * n; ++i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		line[i] = make_pair(make_pair(x1, y1), make_pair(x2, y2));
	}
	vector<vector<int>> adj(6 * n + 1), rev(6 * n + 1);
	for(int u = 1; u <= 3 * n; u += 3){
		int v = u + 1, w = u + 2;
		adj[u].push_back(6 * n + 1 - v);
		rev[6 * n + 1 - v].push_back(u);
		adj[v].push_back(6 * n + 1 - u);
		rev[6 * n + 1 - u].push_back(v);
		adj[u].push_back(6 * n + 1 - w);
		rev[6 * n + 1 - w].push_back(u);
		adj[w].push_back(6 * n + 1 - u);
		rev[6 * n + 1 - u].push_back(w);
		adj[v].push_back(6 * n + 1 - w);
		rev[6 * n + 1 - w].push_back(v);
		adj[w].push_back(6 * n + 1 - v);
		rev[6 * n + 1 - v].push_back(w);
	}
	for(int u = 1; u <= 3 * n; ++u){
		for(int v = 1; v < u; ++v){
			if(intersect(line[u], line[v])){
				adj[6 * n + 1 - u].push_back(v);
				rev[v].push_back(6 * n + 1 - u);
				adj[6 * n + 1 - v].push_back(u);
				rev[u].push_back(6 * n + 1 - v);
			}
		}
	}
	vector<bool> visited(6 * n + 1);
	vector<int> post_order;
	for(int a = 1; a <= 6 * n; ++a){
		traverse(post_order, adj, visited, a);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(6 * n + 1, -1);
	int comp = 0;
	for(int b : post_order){
		if(assigned[b] == -1){
			++comp;
			assign(rev, assigned, b, comp);
		}
	}
	bool sat = true;
	vector<int> to_remove;
	for(int a = 1; a <= 3 * n; ++a){
		if(assigned[a] == assigned[6 * n + 1 - a]){
			sat = false;
			break;
		}else if(assigned[a] > assigned[6 * n + 1 - a]){
			to_remove.push_back(a);
		}
	}
	if(sat){
		cout << to_remove.size() << '\n';
		for(int x : to_remove){
			cout << x << ' ';
		}
	}else{
		cout << -1;
	}
	return 0;
}
