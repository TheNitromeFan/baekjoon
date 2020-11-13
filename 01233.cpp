#include <cstdio>

int main(){
	int s1, s2, s3;
	scanf("%d %d %d", &s1, &s2, &s3);
	int cnt[81] = {};
	for(int i = 1; i <= s1; ++i){
		for(int j = 1; j <= s2; ++j){
			for(int k = 1; k <= s3; ++k){
				++cnt[i + j + k];
			}
		}
	}
	int ans = 0;
	for(int idx = 3; idx <= s1 + s2 + s3; ++idx){
		if(cnt[ans] < cnt[idx]){
			ans = idx;
		}
	}
	printf("%d", ans);
	return 0;
}
