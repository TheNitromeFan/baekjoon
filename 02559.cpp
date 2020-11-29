#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[100000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int running_sum = 0;
	for(int i = 0; i < k; ++i){
		running_sum += a[i];
	}
	int max_sum = running_sum;
	for(int i1 = 0, i2 = k; i2 < n; ++i1, ++i2){
		running_sum += a[i2] - a[i1];
		if(max_sum < running_sum){
			max_sum = running_sum;
		}
	}
	printf("%d", max_sum);
	return 0;
}
