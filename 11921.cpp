#include <cstdio>

/*
int readint(){
	int ret = 0;
	while(true){
		char c = getchar();
		if(!(c >= '0' && c <= '9')){
			break;
		}
		ret = ret * 10 + c - '0';
	}
	return ret;
}
*/

int main(){
	int n;
	scanf("%d", &n);
	if(n > 1000){
		n = 1000;
	}
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		sum += x;
	}
	printf("%d\n%lld", n, sum);
	return 0;
}
