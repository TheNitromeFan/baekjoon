#include <cstdio>

bool repeatless(int n){
	int digits[10] = {};
	while(n > 0){
		int m = n % 10;
		++digits[m];
		if(digits[m] > 1){
			return false;
		}
		n /= 10;
	}
	return true;
}

int main(){
	static int memo[1000001] = {};
	int cur = 0, cnt = 0;
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		while(cur < n){
			++cnt;
			if(repeatless(cnt)){
				++cur;
				memo[cur] = cnt;
			}
		}
		printf("%d\n", memo[n]);
	}
	return 0;
}
