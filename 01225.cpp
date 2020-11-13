#include <cstdio>

int main(){
	char a[10001], b[10001];
	scanf("%s %s", a, b);
	long long ans = 0;
	for(int i = 0; a[i] != '\0'; ++i){
		for(int j = 0; b[j] != '\0'; ++j){
			ans += (a[i] - '0') * (b[j] - '0');
		}
	}
	printf("%lld", ans);
	return 0;
}
