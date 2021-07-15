#include <iostream>

using namespace std;

int f(long long n){
	if(n == 1){
		return 0;
	}
	int exp = 0;
	while(n > (1LL << exp)){
		++exp;
	}
	return (f((1LL << exp) + 1 - n) + exp) % 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long k;
	cin >> k;
	cout << f(k) << '\n';
	return 0;
}
