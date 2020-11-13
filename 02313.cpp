#include <cstdio>
#include <cstdlib>
#include <limits>

int main(){
	int t;
	scanf("%d", &t);
	static long long a[1001][1001] = {};
	long long total = 0;
	long long best_sum[1001] = {};
	long long current_sum[1001] = {};
	long long best_start[1001] = {}, best_end[1001];
	long long current_start[1001] = {}, current_end[1001] = {};
	for(int t0 = 0; t0 < t; ++t0){
		int n;
		scanf("%d", &n);
		best_sum[t0] = std::numeric_limits<int>::min();
		for(int i = 1; i <= n; ++i){
			scanf("%lld", &a[t0][i]);
			if(a[t0][i] > best_sum[t0]){
				best_sum[t0] = a[t0][i];
				best_start[t0] = i;
				best_end[t0] = i;
			}
		}
		current_sum[t0] = 0;
		for(current_end[t0] = 1; current_end[t0] <= n; ++current_end[t0]){
			if(current_sum[t0] > 0){
				current_sum[t0] += a[t0][current_end[t0]];
			}else{
				current_sum[t0] = a[t0][current_end[t0]];
				current_start[t0] = current_end[t0];
			}
			if(current_sum[t0] > best_sum[t0] ||
			(current_sum[t0] == best_sum[t0] && current_end[t0] - current_start[t0] < best_end[t0] - best_start[t0]) ||
			(current_sum[t0] == best_sum[t0] && current_end[t0] - current_start[t0] == best_end[t0] - best_start[t0] && current_start[t0] < best_start[t0])){
				best_sum[t0] = current_sum[t0];
				best_start[t0] = current_start[t0];
				best_end[t0] = current_end[t0];
			}
		}
		total += best_sum[t0];
	}
	printf("%lld\n", total);
	for(int t0 = 0; t0 < t; ++t0){
		printf("%lld %lld\n", best_start[t0], best_end[t0]);
	}
	return 0;
}
