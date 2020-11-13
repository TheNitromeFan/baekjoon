#include <cstdio>
#define MAX 100

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int sum = 0;
	for(int i = 0; i < k - 1; ++i){
		sum += a[i];
	}
	int ans = -10000;
	for(int i = k - 1; i < n; ++i){
		sum += a[i];
		if(sum > ans){
			ans = sum;
		}
		sum -= a[i - k + 1];
	}
	printf("%d", ans);
	return 0;
}
