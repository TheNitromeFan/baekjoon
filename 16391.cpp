#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans *= 2;
		char animal;
		scanf(" %c", &animal);
		ans += (animal == 'O');
	}
	printf("%lld", ans);
	return 0;
}
