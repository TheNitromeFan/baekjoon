#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int a;
		scanf("%d", &a);
		sum += a;
	}
	for(int j = 0; j < m; ++j){
		int b;
		scanf("%d", &b);
		sum -= b;
	}
	printf("%d", sum);
	return 0;
}
