#include <cstdio>

int main(){
	long long n;
	scanf("%lld", &n);
	printf("%s", n % 5 != 0 && n % 5 != 2 ? "SK" : "CY");
	return 0;
}
