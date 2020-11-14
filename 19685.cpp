#include <cstdio>

long long reverse(long long x){
	long long ret = 0;
	while(x > 0){
		ret *= 10;
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

bool palindrome(long long x){
	return x == reverse(x);
}

int main(){
	long long s, e;
	scanf("%lld %lld", &s, &e);
	for(long long i = s; i <= e; ++i){
		if(palindrome(i)){
			printf("Palindrome!\n");
		}else{
			printf("%lld\n", i);
		}
	}
	return 0;
}
