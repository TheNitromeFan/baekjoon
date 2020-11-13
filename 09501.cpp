#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n, d;
		scanf("%d %d", &n, &d);
		int ans = 0;
		for(int j = 0; j < n; ++j){
			int v, f, c;
			scanf("%d %d %d", &v, &f, &c);
			if(v * f >= d * c){
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
