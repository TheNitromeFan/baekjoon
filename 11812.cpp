#include <cstdio>
#include <cstdlib>

void swap(long long &x, long long &y){
	long long t = x;
	x = y;
	y = t;
}

long long traversals(long long x, long long y, int k){
	if(k == 1){
		return llabs(x - y);
	}
	long long ret = 0;
	while(x != y){
		if(x > y){
			swap(x, y);
		}
		y = (y + k - 2) / k;
		++ret;
	}
	return ret;
}

int main(){
	long long n;
	int k, q;
	scanf("%lld %d %d", &n, &k, &q);
	for(int i = 0; i < q; ++i){
		long long x, y;
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", traversals(x, y, k));
	}
	return 0;
}
