#include <cstdio>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		vector<pair<double, double>> v(n);
		vector<pair<long long, long long>> m(n);
		for(int i = 0; i < n; ++i){
			scanf("%lld %lld", &m[i].first, &m[i].second);
			if(i % 2 == 0){
				v[0].first += m[i].first;
				v[0].second += m[i].second;
			}else{
				v[0].first -= m[i].first;
				v[0].second -= m[i].second;
			}
		}
		for(int i = 1; i < n; ++i){
			v[i].first = 2 * m[i - 1].first - v[i - 1].first;
			v[i].second = 2 * m[i - 1].second - v[i - 1].second;
		}
		printf("%d", n);
		for(int i = 0; i < n; ++i){
			printf(" %.6lf %.6lf", v[i].first, v[i].second);
		}
		printf("\n");
	}
	return 0;
}
