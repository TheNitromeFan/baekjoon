#include <cstdio>
#include <limits>
#define MAX (700 + 1)

int main(){
	int tri[MAX][MAX];
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= i; ++j){
			scanf("%d", &tri[i][j]);
		}
	}
	long long ans = std::numeric_limits<long long>::min();
	while(k <= n){
		long long max_sum = std::numeric_limits<long long>::min();
		for(int top_row = 1; top_row + k - 1 <= n; ++top_row){
			for(int top_col = 1; top_col <= top_row; ++top_col){
				long long sum = 0;
				for(int i = top_row; i < top_row + k; ++i){
					for(int j = top_col; j <= top_col + i - top_row; ++j){
						sum += tri[i][j];
						// printf("%d ", tri[i][j]);
					}
				}
				// printf("%lld\n", sum);
				if(max_sum < sum){
					max_sum = sum;
				}
			}
		}
		for(int top_row = k; top_row + k - 1 <= n; ++top_row){
			for(int top_col = 1; top_col + k - 1 <= top_row; ++top_col){
				long long sum = 0;
				for(int i = top_row; i < top_row + k; ++i){
					for(int j = top_col + i - top_row; j < top_col + k; ++j){
						sum += tri[i][j];
						// printf("%d ", tri[i][j]);
					}
				}
				// printf("%lld\n", sum);
				if(max_sum < sum){
					max_sum = sum;
				}
			}
		}
		long long cmp = max_sum / (k * (k + 1) / 2);
		if(ans < cmp){
			ans = cmp;
		}
		++k;
	}
	printf("%lld", ans);
	return 0;
}
