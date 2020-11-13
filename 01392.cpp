#include <cstdio>

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	int beats[10001] = {};
	int time = 0;
	for(int i = 1; i <= n; ++i){
		int bi;
		scanf("%d", &bi);
		for(int j = 0; j < bi; ++j){
			beats[time] = i;
			++time;
		}
	}
	for(int i = 0; i < q; ++i){
		int ti;
		scanf("%d", &ti);
		printf("%d\n", beats[ti]);
	}
	return 0;
}
