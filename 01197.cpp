#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<2>(a) < get<2>(b);
}

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
	}
	return parent[x];
}

void add_set(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x), py = find_parent(parent, y);
	if(px != py){
		parent[py] = px;
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<tuple<int, int, int>> edges;
	edges.resize(m);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges[i] = make_tuple(u, v, w);
	}
	vector<int> parent(n + 1, 0);
	for(int u = 1; u <= n; ++u){
		parent[u] = u;
	}
	sort(edges.begin(), edges.end(), cmp);
	int ans = 0;
	for(auto edge : edges){
		int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			add_set(parent, u, v);
			ans += w;
		}
	}
	printf("%d", ans);
	return 0;
}
