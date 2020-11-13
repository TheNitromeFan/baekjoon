#include <cstdio>

int round(int n){
	int bound = 10;
	while(n > bound){
		if(n % bound >= bound / 2){
			n = (n / bound + 1) * bound;
		}else{
			n = n / bound * bound;
		}
		bound *= 10;
	}
	return n;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		printf("%d\n", round(x));
	}
	return 0;
}
