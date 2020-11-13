#include <cstdio>

int main(){
	int x, y, m;
	scanf("%d %d %d", &x, &y, &m);
	int ans = 0;
	for(int i = 0; y * i <= m; ++i){
		if(ans < y * i + (m - y * i) / x * x){
			ans = y * i + (m - y * i) / x * x;
		}
	}
	printf("%d", ans);
	return 0;
}
