#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int n;
		scanf("%d", &n);
		vector<long long> x(n, 0), y(n, 0);
		for(int j = 0; j < n; ++j){
			scanf("%lld", &x[j]);
		}
		for(int j = 0; j < n; ++j){
			scanf("%lld", &y[j]);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end(), greater<long long>());
		long long ans = 0;
		for(int j = 0; j < n; ++j){
			ans += x[j] * y[j];
		}
		printf("Case #%d: %lld\n", i, ans);
	}
	return 0;
}
