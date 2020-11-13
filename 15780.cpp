#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int sum = 0;
	for(int i = 0; i < k; ++i){
		int x;
		scanf("%d", &x);
		sum += (x + 1) / 2;
	}
	printf("%s", (sum >= n) ? "YES" : "NO");
	return 0;
}
