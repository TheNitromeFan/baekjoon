#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int v;
		scanf("%d", &v);
		int cnt[1001] = {};
		int ans = 0;
		for(int a1 = 0; a1 < v; ++a1){
			int x;
			scanf("%d", &x);
			++cnt[x];
			if(cnt[ans] < cnt[x] || (cnt[ans] == cnt[x] && ans > x)){
				ans = x;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
