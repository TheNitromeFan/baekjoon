#include <cstdio>
#include <cstdlib>
#define MAX 1000

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int x = 0;
	for(int i = 1; i < n; ++i){
		x = gcd(x, abs(a[i] - a[i - 1]));
	}
	printf("%d", x);
	return 0;
}
