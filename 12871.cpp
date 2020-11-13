#include <iostream>
#include <string>
#define MAX (50 + 1)

using namespace std;

unsigned gcd(unsigned a, unsigned b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	string s, t;
	cin >> s >> t;
	unsigned n = s.length(), m = t.length();
	unsigned g = gcd(n, m);
	string s1, s2;
	for(unsigned i = 0; i < m / g; ++i){
		s1 += s;
	}
	for(unsigned j = 0; j < n / g; ++j){
		s2 += t;
	}
	cout << (s1 == s2);
	return 0;
}
