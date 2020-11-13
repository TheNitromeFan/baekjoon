#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dist(pair<int, int> a, pair<int, int> b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool square(vector<pair<int, int>> &v){
	vector<int> d;
	for(unsigned i = 0; i < 4; ++i){
		for(unsigned j = 0; j < i; ++j){
			d.push_back(dist(v[i], v[j]));
		}
	}
	sort(d.begin(), d.end());
	return d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5];
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		vector<pair<int, int>> v;
		v.resize(4);
		for(int i = 0; i < 4; ++i){
			scanf("%d %d", &v[i].first, &v[i].second);
		}
		printf("%d\n", square(v));
	}
	return 0;
}
