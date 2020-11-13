#include <cstdio>

bool squarefree(int n){
	if(n % 4 == 0){
		return false;
	}else if(n % 2 == 0){
		n /= 2;
	}
	for(int p = 3; p * p <= n; p += 2){
		if(n % (p * p) == 0){
			return false;
		}else if(n % p == 0){
			n /= p;
		}
	}
	return true;
}

int notes(int n){
	for(int m = 2; ; ++m){
		if(squarefree(n * m)){
			return m;
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", notes(n));
	return 0;
}
