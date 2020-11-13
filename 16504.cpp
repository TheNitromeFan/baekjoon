#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int x;
			scanf("%d", &x);
			sum += x;
		}
	}
	printf("%lld", sum);
	return 0;
}
