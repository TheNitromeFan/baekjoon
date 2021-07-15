#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

bool intersect(int a, int b, int c, int d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	return !(b < c || d < a);
}

bool cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int cmp1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int cmp2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if(cmp1 == 0 && cmp2 == 0){
		return intersect(x1, x2, x3, x4) && intersect(y1, y2, y3, y4);
	}
	return cmp1 <= 0 && cmp2 <= 0;
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
	int w, p;
	cin >> w >> p;
	vector<tuple<int, int>> wells(w + 1);
	for(int i = 1; i <= w; ++i){
		cin >> get<0>(wells[i]) >> get<1>(wells[i]);
	}
	vector<tuple<int, int, int>> pipes(p + 1);
	for(int j = 1; j <= p; ++j){
		cin >> get<0>(pipes[j]) >> get<1>(pipes[j]) >> get<2>(pipes[j]);
	}
	vector<vector<int>> adj(2 * p + 1), rev(2 * p + 1);
	for(int j = 1; j <= p; ++j){
		int m = get<0>(pipes[j]);
		int x1 = get<0>(wells[m]), y1 = get<1>(wells[m]), x2 = get<1>(pipes[j]), y2 = get<2>(pipes[j]);
		for(int k = 1; k < j; ++k){
			int n = get<0>(pipes[k]);
			if(m == n){
				continue;
			}
			int x3 = get<0>(wells[n]), y3 = get<1>(wells[n]), x4 = get<1>(pipes[k]), y4 = get<2>(pipes[k]);
			if(cross(x1, y1, x2, y2, x3, y3, x4, y4)){
				adj[2 * p + 1 - k].push_back(j);
				rev[j].push_back(2 * p + 1 - k);
				adj[2 * p + 1 - j].push_back(k);
				rev[k].push_back(2 * p + 1 - j);
				adj[k].push_back(2 * p + 1 - j);
				rev[2 * p + 1 - j].push_back(k);
				adj[j].push_back(2 * p + 1 - k);
				rev[2 * p + 1 - k].push_back(j);
			}
		}
	}
	vector<bool> visited(2 * p + 1);
	vector<int> post_order;
	for(int a = 1; a <= 2 * p; ++a){
		traverse(post_order, adj, visited, a);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(2 * p + 1, -1);
	int comp = 0;
	for(int b : post_order){
		if(assigned[b] == -1){
			++comp;
			assign(rev, assigned, b, comp);
		}
	}
	bool possible = true;
	for(int a = 1; a <= p; ++a){
		if(assigned[a] == assigned[2 * p + 1 - a]){
			possible = false;
			break;
		}
	}
	cout << (possible ? "possible\n" : "impossible\n");
	return 0;
}
