#include <cstdio>
#define MAX (200000 + 1)

int main(){
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	int c[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &c[i]);
	}
	for(int j = 0; j < m; ++j){
		int k;
		scanf("%d", &k);
		if(k + 1 < v){
			printf("%d\n", c[k + 1]);
		}else{
			printf("%d\n", c[(k - (v - 1)) % (n - (v - 1)) + v]);
		}
	}
	return 0;
}
