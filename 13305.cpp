#include <cstdio>
#define MAX 100000

int main(){
	int n;
	scanf("%d", &n);
	int dist[MAX];
	for(int i = 0; i < n - 1; ++i){
		scanf("%d", &dist[i]);
	}
	int cur = 1000000001;
	long long ans = 0;
	for(int i = 0; i < n - 1; ++i){
		int val;
		scanf("%d", &val);
		if(cur > val){
			cur = val;
		}
		ans += (long long)cur * dist[i];
	}
	printf("%lld", ans);
	return 0;
}
