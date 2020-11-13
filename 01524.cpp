#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		int max_s = -1000000, max_b = -1000000;
		for(int i = 0; i < n; ++i){
			int x;
			scanf("%d", &x);
			if(max_s < x){
				max_s = x;
			}
		}
		for(int j = 0; j < m; ++j){
			int x;
			scanf("%d", &x);
			if(max_b < x){
				max_b = x;
			}
		}
		printf("%c\n", max_s >= max_b ? 'S' : 'B');
	}
	return 0;
}
