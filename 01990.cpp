#include <iostream>

using namespace std;

int powers_of_ten[5] = {1, 10, 100, 1000, 10000};

int palindromes[20000];

int make_palindrome(int n, bool repeat){
	int normal = repeat ? n / 10 : n;
	int reversed = 0;
	while(normal){
		reversed = reversed * 10 + (normal % 10);
		n *= 10;
		normal /= 10;
	}
	return n + reversed;
}

void preprocess(){
	int pal_i = 0;
	for(int i = 0; i < 4; ++i){
		for(int n = powers_of_ten[i]; n < powers_of_ten[i+1]; ++n){
			palindromes[pal_i] = make_palindrome(n, true);
			++pal_i;
		}
		for(int n = powers_of_ten[i]; n < powers_of_ten[i+1]; ++n){
			palindromes[pal_i] = make_palindrome(n, false);
			++pal_i;
		}
	}
}

bool is_prime(int n){
	if(n == 1){
		return false;
	}else if(n == 2){
		return true;
	}else if(n % 2 == 0){
		return false;
	}
	for(int p = 3; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	preprocess();
	int a, b;
	cin >> a >> b;
	for(int i = 0; i < 19998; ++i){
		int tmp = palindromes[i];
		if(tmp > b){
			break;
		}else if(tmp >= a && is_prime(tmp)){
			printf("%d\n", tmp);
		}
	}
	printf("-1");
	return 0;
}
