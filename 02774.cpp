#include <cstdio>

int pretty(int n){
	bool appears[10] = {};
	while(n){
		appears[n % 10] = true;
		n /= 10;
	}
	int ret = 0;
	for(int i = 0; i < 10; ++i){
		if(appears[i]){
			++ret;
		}
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int x;
		scanf("%d", &x);
		printf("%d\n", pretty(x));
	}
	return 0;
}
