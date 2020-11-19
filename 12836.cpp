#include <cstdio>

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	long long day[10001] = {};
	for(int i = 0; i < q; ++i){
		int t, p, x;
		scanf("%d %d %d", &t, &p, &x);
		if(t == 1){
			day[p] += x;
		}else{
			long long sum = 0;
			for(int d = p; d <= x; ++d){
				sum += day[d];
			}
			printf("%lld\n", sum);
		}
	}
	return 0;
}
