#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int n, len;
		scanf("%d %d", &n, &len);
		vector<int> p(n, 0);
		for(int j = 0; j < n; ++j){
			scanf("%d", &p[j]);
		}
		sort(p.begin(), p.end());
		int est = 0, total = 0;
		int idx = 0;
		while(idx < n && est + p[idx] <= len){
			est += p[idx];
			total += est;
			++idx;
		}
		printf("Case %d: %d %d %d\n", i, idx, est, total);
	}
	return 0;
}
