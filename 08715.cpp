#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a[1000001] = {};
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		if(x < 1 || x > n || a[x] > 0){
			printf("NIE");
			return 0;
		}
		++a[x];
	}
	printf("TAK");
	return 0;
}
