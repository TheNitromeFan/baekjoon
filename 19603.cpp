#include <cstdio>

int main(){
	int p, n, r;
	scanf("%d %d %d", &p, &n, &r);
	int d = 0;
	if(r > 1){
		int infected = 1;
		int exp = n;
		while(infected <= p){
			++d;
			exp *= r;
			infected += exp;
		}
	}else{
		d = p / n;
	}
	printf("%d", d);
	return 0;
}
