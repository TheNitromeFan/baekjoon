#include <cstdio>

bool nasty(int n){
	for(int a = 1; a * a <= n; ++a){
		if(n % a != 0){
			continue;
		}
		for(int b = 1; b <= a; ++b){
			if(n % b != 0){
				continue;
			}
			if(n / b - b == a + n / a){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		printf("%d is %s\n", n, nasty(n) ? "nasty" : "not nasty");
	}
	return 0;
}
