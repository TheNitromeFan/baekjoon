#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int q = (n - 1) / 8, r = (n - 1) % 8 + 1;
	int m = 15 * q;
	while(r > 0){
		++m;
		if(m % 3 != 0 && m % 5 != 0){
			--r;
		}
	}
	printf("%d", m);
	return 0;
}
