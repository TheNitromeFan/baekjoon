#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		vector<pair<int, int>> v;
		v.resize(n);
		for(int j = 0; j < n; ++j){
			scanf("%d %d", &v[j].first, &v[j].second);
		}
		sort(v.begin(), v.end());
		vector<pair<int, int>> cnd = {v[0]};
		for(int j = 1; j < n; ++j){
			if(cnd[cnd.size() - 1].second > v[j].second){
				cnd.push_back(v[j]);
			}
		}
		printf("%llu\n", cnd.size());
	}
	return 0;
}
