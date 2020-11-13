#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int ans = 0;
		while(n >= 5){
			ans += n / 5;
			n /= 5;
		}
		printf("%d\n", ans);
	}
	return 0;
}
