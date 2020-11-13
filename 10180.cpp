#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, d;
		scanf("%d %d", &n, &d);
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			int v, f, c;
			scanf("%d %d %d", &v, &f, &c);
			if(v * f >= d * c){
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
