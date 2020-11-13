#include <cstdio>

int main(){
	int n, p, h;
	scanf("%d %d %d", &n, &p, &h);
	int prev = p;
	for(int i = 0; i < n; ++i){
		int cur;
		scanf("%d", &cur);
		if(cur < prev){
			printf("NTV: Dollar dropped by %d Oshloobs\n", prev - cur);
		}else if(cur > h){
			printf("BBTV: Dollar reached %d Oshloobs, A record!\n", cur);
			h = cur;
		}
		prev = cur;
	}
	return 0;
}
