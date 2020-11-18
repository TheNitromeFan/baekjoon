#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int k;
		scanf("%d", &k);
		int line[20];
		int cnt = 0;
		for(int j = 0; j < 20; ++j){
			int x;
			scanf("%d", &x);
			int k = 0;
			for(; k < j; ++k){
				if(x < line[k]){
					for(int l = j; l > k; --l){
						++cnt;
						line[l] = line[l - 1];
					}
					break;
				}
			}
			line[k] = x;
		}
		printf("%d %d\n", k, cnt);
	}
	return 0;
}
