#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	bool sticker[100001] = {};
	int cnt = 0;
	int max = 0;
	for(int i = 0; i < 2 * n; ++i){
		int x;
		scanf("%d", &x);
		if(sticker[x]){
			--cnt;
		}else{
			sticker[x] = true;
			++cnt;
			if(cnt > max){
				max = cnt;
			}
		}
	}
	printf("%d", max);
	return 0;
}
