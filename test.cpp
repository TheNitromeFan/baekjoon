#include <iostream>
#include <limits>
#include <string>

using namespace std;



void extended_gcd(long long a, long long b, long long &x, long long &y, long long &g){
	long long r, r1, r2, a1, a2, b1, b2, q;
	a1 = b2 = 1;
	a2 = b1 = 0;
	while (b > 0){
		q = a / b;
		r = a % b;
		r1 = a1 - q*b1;
		r2 = a2 - q*b2;
		a = b;
		a1 = b1;
		a2 = b2;
		b = r;
		b1 = r1;
		b2 = r2;
	}
	x = a1;
	y = a2;
	g = a;
}

int main(){
	long long x, y, g;
	extended_gcd(7, 3, x, y, g);
	cout << x << ' ' << y << ' ' << g;
	return 0;
}
