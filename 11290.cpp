#include <cstdio>
#include <vector>

using std::vector;

vector<bool> is_prime(10001, true);

void initialize(){
	is_prime[0] = false;
	is_prime[1] = false;
	for(int j = 2; 2 * j <= 10000; ++j){
		is_prime[2 * j] = false;
	}
	for(int p = 3; p <= 10000; p += 2){
		for(int j = 2; p * j <= 10000; ++j){
			is_prime[p * j] = false;
		}
	}
}

int wonowon(int p){
	int pow10 = 1;
	int exp = 0;
	do{
		pow10 *= 100;
		pow10 %= p;
		exp += 2;
	}while((pow10 - 1) % p != 0);
	// printf("%d: %d\n", p, exp - 1);
	return exp - 1;
}

int main(){
	initialize();
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 7; i <= n; i += 2){
		if(i == 11){
			continue;
		}
		if(is_prime[i] && wonowon(i) == i - 2){
			// printf("%d\n", i);
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
