#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n, k;
		scanf("%d %d", &n, &k);
		printf("Case #%d: %s\n", a0, (k % (1 << n) == (1 << n) - 1) ? "ON" : "OFF");
	}
	return 0;
}
