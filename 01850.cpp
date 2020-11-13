#include <iostream>

using std::cin;
using std::cout;

static long long gcd(long long a, long long b){
	if(b == 0LL)
		return a;
	else
		return gcd(b, a % b);
}

int main(){
	long long a = 0LL, b = 0LL;
	cin >> a >> b;
	long long g = gcd(a, b);
	for(long long i = 0; i < g; ++i)
		cout << "1";
	return 0;
}
