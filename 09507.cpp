#include <cstdio>
#define MAX 69

int main(){
	long long kfib[MAX] = {};
	kfib[0] = 1;
	kfib[1] = 1;
	kfib[2] = 2;
	kfib[3] = 4;
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		if(kfib[n]){
			printf("%lld\n", kfib[n]);
			continue;
		}
		for(int j = 4; j <= n; ++j){
			kfib[j] = kfib[j - 1] + kfib[j - 2] + kfib[j - 3] + kfib[j - 4];
		}
		printf("%lld\n", kfib[n]);
	}
	return 0;
}
