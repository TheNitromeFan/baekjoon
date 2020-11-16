#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt[1001] = {};
	int maxCnt = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		++cnt[x];
		if(maxCnt < cnt[x]){
			maxCnt = cnt[x];
		}
	}
	printf("%d", maxCnt);
	return 0;
}
