#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string hexdigits = "0123456789ABCDEF";

string to_base(long long number, int base){
	string ret;
	while(number){
		ret += hexdigits[number % base];
		number /= base;
	}
	return ret;
}

bool is_palindrome(string s){
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		long long a;
		int n;
		scanf("%lld %d", &a, &n);
		printf("%d\n", is_palindrome(to_base(a, n)));
	}
	return 0;
}
