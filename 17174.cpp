#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 0;
	while(n > 0){
		ans += n;
		n /= m;
	}
	printf("%d", ans);
	return 0;
}
