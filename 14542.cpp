#include <cstdio>

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int sum = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= i; ++j){
				int x;
				scanf("%d", &x);
				if(i == n || j == 1 || j == i){
					sum += x;
				}
			}
		}
		printf("Case #%d:%d \n", cnt, sum);
	}
	return 0;
}
