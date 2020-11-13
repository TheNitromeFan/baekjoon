#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		int a[1000], b[1000];
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &a[i], &b[i]);
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < i; ++j){
				if((a[j] - a[i]) * (b[j] - b[i]) < 0){
					++cnt;
				}
			}
		}
		printf("Case #%d: %d\n", a0, cnt);
	}
	return 0;
}
