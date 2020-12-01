#include <cstdio>

int main(){
	int n, k, b;
	scanf("%d %d %d", &n, &k, &b);
	bool broken[100001] = {};
	for(int i = 0; i < b; ++i){
		int x;
		scanf("%d", &x);
		broken[x] = true;
	}
	int running_sum = 0;
	for(int j = 1; j <= k; ++j){
		running_sum += broken[j];
	}
	int min_running_sum = running_sum;
	for(int i = 1, j = k + 1; j <= n; ++i, ++j){
		running_sum += broken[j] - broken[i];
		if(running_sum < min_running_sum){
			min_running_sum = running_sum;
		}
	}
	printf("%d", min_running_sum);
	return 0;
}
