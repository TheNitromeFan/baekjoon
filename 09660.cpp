#include <cstdio>

int main(){
	long long n;
	scanf("%lld", &n);
	printf("%s", n % 7 != 0 && n % 7 != 2 ? "SK" : "CY");
	return 0;
}
