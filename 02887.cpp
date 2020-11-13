#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int find_parent(vector<int> &parent, int x){
	if(parent[x] != x){
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

bool cmp1(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
	return get<0>(a) < get<0>(b);
}

bool cmp2(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
	return get<1>(a) < get<1>(b);
}

bool cmp3(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
	return get<2>(a) < get<2>(b);
}

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<2>(a) < get<2>(b);
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> parent(n);
	for(int i = 0; i < n; ++i){
		parent[i] = i;
	}
	vector<tuple<int, int, int, int>> planets(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d %d", &get<0>(planets[i]), &get<1>(planets[i]), &get<2>(planets[i]));
		get<3>(planets[i]) = i;
	}
	vector<tuple<int, int, int>> edges;
	sort(planets.begin(), planets.end(), cmp1);
	for(int i = 0; i < n - 1; ++i){
		edges.push_back(make_tuple(get<3>(planets[i]), get<3>(planets[i + 1]), get<0>(planets[i + 1]) - get<0>(planets[i])));
	}
	sort(planets.begin(), planets.end(), cmp2);
	for(int i = 0; i < n - 1; ++i){
		edges.push_back(make_tuple(get<3>(planets[i]), get<3>(planets[i + 1]), get<1>(planets[i + 1]) - get<1>(planets[i])));
	}
	sort(planets.begin(), planets.end(), cmp3);
	for(int i = 0; i < n - 1; ++i){
		edges.push_back(make_tuple(get<3>(planets[i]), get<3>(planets[i + 1]), get<2>(planets[i + 1]) - get<2>(planets[i])));
	}
	sort(edges.begin(), edges.end(), cmp);
	long long ans = 0;
	for(auto edge : edges){
		int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			add_set(parent, u, v);
			ans += w;
		}
	}
	printf("%lld", ans);
	return 0;
}
