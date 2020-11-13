#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n, m;
		scanf("%d %d", &n, &m);
		int ans = 0;
		for(int b = 1; b < n; ++b){
			for(int a = 1; a < b; ++a){
				if((a * a + b * b + m) % (a * b) == 0){
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
