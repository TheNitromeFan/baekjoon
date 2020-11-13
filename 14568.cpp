#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int a = 2; n - a >= 4; a += 2){
		ans += (n - a - 2) / 2;
	}
	printf("%d", ans);
	return 0;
}
