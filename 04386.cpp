#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
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

double dist(pair<double, double> a, pair<double, double> b){
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
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
	vector<pair<double, double>> points(n);
	for(int i = 0; i < n; ++i){
		scanf("%lf %lf", &points[i].first, &points[i].second);
	}
	vector<tuple<int, int, double>> edges;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			edges.push_back(make_tuple(j, i, dist(points[j], points[i])));
		}
	}
	sort(edges.begin(), edges.end(), cmp);
	double ans = 0;
	for(auto edge : edges){
		int u = get<0>(edge), v = get<1>(edge);
		double w = get<2>(edge);
		if(find_parent(parent, u) != find_parent(parent, v)){
			add_set(parent, u, v);
			ans += w;
		}
	}
	printf("%f", ans);
	return 0;
}
