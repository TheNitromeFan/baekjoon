#include <cstdio>
#define MAX 15

int main(){
	int n;
	long long w;
	scanf("%d %lld", &n, &w);
	long long s[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%lld", &s[i]);
	}
	for(int i = 0; i < n - 1; ++i){
		if(s[i] < s[i + 1]){
			long long coins = w / s[i];
			w %= s[i];
			w += coins * s[i + 1];
		}
	}
	printf("%lld", w);
	return 0;
}
