#include <cstdio>

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	int prev;
	scanf("%d", &prev);
	int curCnt = 1, maxCnt = 0;
	for(int i = 1; i < n; ++i){
		int cur;
		scanf("%d", &cur);
		if(cur - prev <= x){
			++curCnt;
		}else{
			if(curCnt > maxCnt){
				maxCnt = curCnt;
			}
			curCnt = 1;
		}
		prev = cur;
	}
	if(curCnt > maxCnt){
		maxCnt = curCnt;
	}
	printf("%d", maxCnt);
	return 0;
}
