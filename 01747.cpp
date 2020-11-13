#include <cstdio>

bool prime(int n){
	if(n == 1){
		return false;
	}
	for(int p = 2; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

bool palindrome(int n){
	int original = n, reverse = 0;
	while(n){
		reverse *= 10;
		reverse += n % 10;
		n /= 10;
	}
	return reverse == original;
}

int main(){
	int n;
	scanf("%d", &n);
	int ans = n;
	while(true){
		if(prime(ans) && palindrome(ans)){
			break;
		}
		++ans;
	}
	printf("%d", ans);
	return 0;
}
