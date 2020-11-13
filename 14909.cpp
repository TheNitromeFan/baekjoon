#include <cstdio>

int main(){
	int n;
	int ans = 0;
	while(scanf("%d", &n) == 1){
		if(n > 0){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
