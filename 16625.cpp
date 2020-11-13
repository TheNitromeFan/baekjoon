#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int main(){
	int a, b, s;
	scanf("%d %d %d", &a, &b, &s);
	printf("%s", lcm(a, b) <= s ? "yes" : "no");
	return 0;
}
