#include <cstdio>

int fruits(int a[1000], int n, int c, int start){
	int cnt = 0;
	int weight = 0;
	for(int i = start; i < n; ++i){
		if(weight + a[i] <= c){
			weight += a[i];
			++cnt;
		}
	}
	return cnt;
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	int a[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int cmp = fruits(a, n, c, i);
		if(ans < cmp){
			ans = cmp;
		}
	}
	printf("%d", ans);
	return 0;
}
