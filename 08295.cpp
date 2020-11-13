#include <cstdio>

int main(){
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(2 * (i + j) >= p){
				cnt += (n - i + 1) * (m - j + 1);
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
