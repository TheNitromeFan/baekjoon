#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bool lights[501] = {};
	for(int i = 1; i <= m; ++i){
		int op, s, e;
		scanf("%d %d %d", &op, &s, &e);
		if(op){
			int ans = 0;
			for(int j = s; j <= e; ++j){
				if(lights[j]){
					++ans;
				}
			}
			printf("%d\n", ans);
		}else{
			for(int j = s; j <= e; ++j){
				lights[j] = !lights[j];
			}
		}
	}
	return 0;
}
