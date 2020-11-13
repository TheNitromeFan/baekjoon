#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long prev;
	scanf("%lld", &prev);
	long long energy = 0;
	for(int i = 1; i < n; ++i){
		long long cur;
		scanf("%lld", &cur);
		energy += (cur - prev) * (cur - prev);
		prev = cur;
	}
	printf("%lld", energy);
	return 0;
}
