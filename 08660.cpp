#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int negCnt = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x < 0){
			++negCnt;
		}
	}
	printf("%lld", (long long)negCnt * (n - 1));
	return 0;
}
