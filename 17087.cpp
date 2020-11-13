#include <cstdio>
#include <cstdlib>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int n, s;
	scanf("%d %d", &n, &s);
	int a;
	scanf("%d", &a);
	int d = abs(s - a);
	for(int i = 1; i < n; ++i){
		scanf("%d", &a);
		d = gcd(abs(s - a), d);
	}
	printf("%d", d);
	return 0;
}
