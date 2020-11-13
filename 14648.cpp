#include <cstdio>
#include <algorithm>

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	int arr[1001];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &arr[i]);
	}
	for(int j = 0; j < q; ++j){
		int opt;
		scanf("%d", &opt);
		if(opt == 1){
			int a, b;
			scanf("%d %d", &a, &b);
			long long sum = 0;
			for(int k = a; k <= b; ++k){
				sum += arr[k];
			}
			printf("%lld\n", sum);
			std::swap(arr[a], arr[b]);
		}else{
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			long long sum1 = 0, sum2 = 0;
			for(int k = a; k <= b; ++k){
				sum1 += arr[k];
			}
			for(int k = c; k <= d; ++k){
				sum2 += arr[k];
			}
			printf("%lld\n", sum1 - sum2);
		}
	}
	return 0;
}
