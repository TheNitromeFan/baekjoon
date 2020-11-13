#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	int n;
	long long m;
	scanf("%d %lld", &n, &m);
	vector<pair<int, int>> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i].first);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i].second);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n && v[i].first <= m; ++i){
		if(v[i].first < v[i].second){
			m += v[i].second - v[i].first;
		}
	}
	printf("%lld", m);
	return 0;
}
