#include <cstdio>

bool is_prime(int n){
	if(n == 1){
		return false;
	}else if(n == 2){
		return true;
	}else if(n % 2 == 0){
		return false;
	}
	for(int p = 3; p * p <= n; p += 2){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int m, n;
	scanf("%d\n%d", &m, &n);
	int sum = 0, min;
	for(int x = m; x <= n; ++x){
		if(is_prime(x)){
			if(sum == 0){
				min = x;
			}
			sum += x;
		}
	}
	if(sum == 0){
		printf("-1");
	}else{
		printf("%d\n%d", sum, min);
	}
	return 0;
}
