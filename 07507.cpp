#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int m;
		scanf("%d", &m);
		vector<pair<int, int>> v;
		v.resize(m);
		for(int j = 0; j < m; ++j){
			int d, s, e;
			scanf("%d %d %d", &d, &s, &e);
			int start = 24 * 60 * (d - 1) + 60 * (s / 100) + s % 100;
			int end = 24 * 60 * (d - 1) + 60 * (e / 100) + e % 100;
			v[j] = make_pair(start, end);
		}
		sort(v.begin(), v.end(), cmp);
		int time = v[0].second;
		int cnt = 1;
		for(int j = 1; j < m; ++j){
			if(v[j].first >= time){
				time = v[j].second;
				++cnt;
			}
		}
		printf("Scenario #%d:\n%d\n\n", i, cnt);
	}
	return 0;
}
