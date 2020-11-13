#include <cstdio>

int main(){
	while(true){
		long long a, b, c;
		scanf("%lld %lld %lld\n", &a, &b, &c);
		if(a == 0 && b == 0 && c == 0){
			break;
		}
		if(2 * b == a + c){
			printf("AP %lld\n", c + b - a);
		}else{
			printf("GP %lld\n", c * b / a);
		}
	}
	return 0;
}
