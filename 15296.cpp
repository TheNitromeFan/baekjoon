#include <cstdio>

unsigned ssd(unsigned b, unsigned n){
	unsigned ret = 0;
	while(n > 0){
		ret += (n % b) * (n % b);
		n /= b;
	}
	return ret;
}

int main(){
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; ++i){
		unsigned k, b, n;
		scanf("%u %u %u", &k, &b, &n);
		printf("%u %u\n", k, ssd(b, n));
	}
	return 0;
}
