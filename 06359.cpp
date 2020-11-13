#include <cstdio>

int main(){
	bool open[101] = {};
	for(int k = 1; k <= 100; ++k){
		for(int i = k; i <= 100; i += k){
			open[i] = !open[i];
		}
	}
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int cnt = 0;
		for(int j = 1; j <= n; ++j){
			if(open[j]){
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
