#include <iostream>

using std::cin;
using std::cout;

static long long power(long long a, unsigned b, unsigned c){
	if(b == 1U)
		return a % c;
	else if(b % 2 == 1U)
		return power(a*a % c, b/2, c) * (a % c) % c;
	else
		return power(a*a % c, b/2, c) % c;
}

int main(){
	long long a = 1LL;
	unsigned b = 1U, c = 1U;
	cin >> a >> b >> c;
	cout << power(a, b, c);
	return 0;
}
