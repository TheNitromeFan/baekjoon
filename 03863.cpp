#include <cstdio>

int main(){
	while(true){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		int low[10000], high[10000];
		for(int i = 0; i < n; ++i){
			int src, dest, start, dur;
			scanf("%d %d %d %d", &src, &dest, &start, &dur);
			low[i] = start;
			high[i] = start + dur;
		}
		for(int j = 0; j < m; ++j){
			int start, dur;
			scanf("%d %d", &start, &dur);
			int cnt = 0;
			for(int k = 0; k < n; ++k){
				if(!(high[k] <= start || low[k] >= start + dur)){
					++cnt;
				}
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
