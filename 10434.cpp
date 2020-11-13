#include <cstdio>

int sum_of_squared_digits(int n){
	int ret = 0;
	while(n){
		ret += (n % 10) * (n % 10);
		n /= 10;
	}
	return ret;
}

bool prime(int n){
	if(n == 1){
		return false;
	}
	for(int i = 2; i * i <= n; ++i){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

bool happy(int n){
	while(true){
		if(n == 1){
			return true;
		}else if(n == 4){
			return false;
		}
		n = sum_of_squared_digits(n);
	}
}

int main(){
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; ++i){
		int k, m;
		scanf("%d %d", &k, &m);
		printf("%d %d %s\n", k, m, prime(m) && happy(m) ? "YES" : "NO");
	}
	return 0;
}
