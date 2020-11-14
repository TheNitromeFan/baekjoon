#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[500], b[500];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	for(int j = 0; j < m; ++j){
		scanf("%d", &b[j]);
	}
	int i1 = 0, j1 = 0;
	while(i1 < n || j1 < m){
		if(i1 == n){
			printf("%d\n", b[j1]);
			++j1;
		}else if(j1 == m){
			printf("%d\n", a[i1]);
			++i1;
		}else if(a[i1] > b[j1]){
			printf("%d\n", b[j1]);
			++j1;
		}else{
			printf("%d\n", a[i1]);
			++i1;
		}
	}
	return 0;
}
