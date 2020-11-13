#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 8;
	if(n >= 3){
		int ruleTimes[8] = {n + (n - 1) / 3 + 1,
							(n + 1) / 2 + (n - 1) / 3 + 1,
							n / 2 + (n - 1) / 3 + 1,
							n,
							(n + 1) / 2,
							n / 2,
							(n - 1) / 3 + 1,
							0};
		for(int i = 0; i < 8; ++i){
			if(ruleTimes[i] > m){
				--ans;
			}
		}
	}else if(n == 2){
		if(m == 0){
			ans = 1;
		}else if(m == 1){
			ans = 3;
		}else{
			ans = 4;
		}
	}else{
		if(m == 0){
			ans = 1;
		}else{
			ans = 2;
		}
	}
	printf("%d", ans);
	return 0;
}
