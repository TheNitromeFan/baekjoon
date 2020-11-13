#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int h[30000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &h[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		for(int j = i + 1; j < n; ++j){
			if(h[j] > h[i]){
				break;
			}
			++cnt;
		}
		if(cnt > ans){
			ans = cnt;
		}
	}
	printf("%d", ans);
	return 0;
}
