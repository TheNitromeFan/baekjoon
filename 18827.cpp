#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long long best_sum = numeric_limits<long long>::min() / 2;
	long long current_sum = 0;
	for(int i = 0; i < n; ++i){
		long long x;
		scanf("%lld", &x);
		current_sum = max(x, current_sum + x);
		best_sum = max(best_sum, current_sum);
	}
	printf("%lld", best_sum);
	return 0;
}
