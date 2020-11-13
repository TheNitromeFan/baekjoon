#include <cstdio>

int main(){
	int k;
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i){
		int p, m;
		scanf("%d %d", &p, &m);
		bool taken[501] = {};
		int cnt = 0;
		for(int j = 0; j < p; ++j){
			int seat;
			scanf("%d", &seat);
			if(taken[seat]){
				++cnt;
			}else{
				taken[seat] = true;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
