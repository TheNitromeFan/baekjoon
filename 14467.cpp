#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	stable_sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for(int i = 0; i < n - 1; ++i){
		if(v[i].first == v[i + 1].first && v[i].second != v[i + 1].second){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
