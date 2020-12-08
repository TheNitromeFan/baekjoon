#include <cstdio>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		vector<pair<long long, long long>> v(n);
		for(int i = 0; i < n; ++i){
			scanf("%lld %lld", &v[i].first, &v[i].second);
		}
		printf("%d", n);
		for(int i = 0; i < n; ++i){
			printf(" %.6lf %.6lf",
			(v[i].first + v[(i + 1) % n].first) / 2.0,
			(v[i].second + v[(i + 1) % n].second) / 2.0);
		}
		printf("\n");
	}
	return 0;
}
