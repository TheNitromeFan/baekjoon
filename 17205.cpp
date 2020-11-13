#include <cstdio>

int main(){
	long long d[11] = {};
	d[1] = 1;
	long long power_of_26 = 1;
	for(int i = 2; i <= 10; ++i){
		power_of_26 *= 26;
		d[i] = d[i - 1] + power_of_26;
	}
	int n;
	scanf("%d", &n);
	char pass[11];
	scanf("%s", pass);
	long long ans = 0;
	for(int i = 0; pass[i] != '\0'; ++i){
		ans += d[n - i] * (pass[i] - 'a') + 1;
	}
	printf("%lld", ans);
	return 0;
}
