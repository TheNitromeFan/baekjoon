#include <cstdio>

int main(){
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	int minCost = -1;
	for(int i = 0; i < n; ++i){
		int cost, m;
		scanf("%d %d", &cost, &m);
		int cnt = 0;
		for(int j = 0; j < m; ++j){
			int c;
			scanf("%d", &c);
			if((cnt == 0 && c == a) || (cnt == 1 && c == b)){
				++cnt;
			}
		}
		if(cnt == 2 && (minCost == -1 || minCost > cost)){
			minCost = cost;
		}
	}
	printf("%d", minCost);
	return 0;
}
