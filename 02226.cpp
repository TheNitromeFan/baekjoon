#include <cstdio>

int main(){
	long long a = 0, b = 1;
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		long long c, d;
		if(i % 2 == 0){
			c = a + b - 1;
		}else{
			c = a + b;
		}
		d = a + b;
		a = c;
		b = d;
	}
	printf("%lld", a);
	return 0;
}
