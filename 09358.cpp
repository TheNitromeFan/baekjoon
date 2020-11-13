#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		int a[101];
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		while(n > 2){
			for(int i = 1; i <= (n + 1) / 2; ++i){
				a[i] += a[n + 1 - i];
			}
			n = (n + 1) / 2;
		}
		printf("Case #%d: %s\n", a0, (a[1] > a[2]) ? "Alice" : "Bob");
	}
	return 0;
}
