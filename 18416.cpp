#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int prev;
	scanf("%d", &prev);
	int maxCnt = 1, cnt = 1;
	for(int i = 1; i < n; ++i){
		int cur;
		scanf("%d", &cur);
		if(prev <= cur){
			++cnt;
		}else{
			if(cnt > maxCnt){
				maxCnt = cnt;
			}
			cnt = 1;
		}
		prev = cur;
	}
	if(cnt > maxCnt){
		maxCnt = cnt;
	}
	printf("%d", maxCnt);
	return 0;
}
