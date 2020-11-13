#include <cstdio>
#include <cstdlib>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int ans = abs(a - b);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(ans > abs(x - b) + 1){
			ans = abs(x - b) + 1;
		}
	}
	printf("%d", ans);
	return 0;
}
