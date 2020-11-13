#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 1;
	while(n > 1){
		if(n % 2 == 0){
			n /= 2;
		}else{
			n = 3 * n + 1;
		}
		++ans;
	}
	printf("%d", ans);
	return 0;
}
