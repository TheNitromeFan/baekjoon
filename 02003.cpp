#include <cstdio>
#define MAX 10000

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[MAX+1];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int sum[MAX+1] = {};
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		sum[i] = sum[i-1] + a[i];
		for(int j = i-1; j >= 0; --j){
			if(sum[i] - sum[j] == m){
				++ans;
			}
			if(sum[i] - sum[j] >= m){
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
