#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	long long n;
	scanf("%lld", &n);
	printf("%lld", n + (long long)(0.5 + sqrt(n)));
	return 0;
}
