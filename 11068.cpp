#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+-";

string change_base(int n, int base){
	string ret;
	while(n){
		ret += digits[n % base];
		n /= base;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool palindrome(string s){
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

bool palindrome_in_any_base(int n){
	for(int b = 2; b <= 64; ++b){
		string m = change_base(n, b);
		if(palindrome(m)){
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		printf("%d\n", palindrome_in_any_base(n));
	}
	return 0;
}
