#include <cstdio>

int main(){
	while(true){
		int x;
		scanf("%d", &x);
		if(x == 0){
			break;
		}
		int n = 50, cnt = 1;
		int low = 2, high = 100;
		while(n != x){
			++cnt;
			if(n % 2 != x % 2){
				--n;
				--low;
				--high;
				continue;
			}
			if(n > x){
				high = n - 2;
			}else{
				low = n + 2;
			}
			n = (low + high) / 2;
			if(n % 2 != x % 2){
				--n;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
