#include <iostream>
#include <string>

using namespace std;

long long gray_to_binary(string &s, int n){
	long long ret = 0;
	int pxor = 0;
	for(int i = 0; i < n; ++i){
		ret <<= 1;
		pxor ^= s[i] - '0';
		ret |= pxor;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string a, b;
	cin >> n >> a >> b;
	long long a1 = gray_to_binary(a, n);
	long long b1 = gray_to_binary(b, n);
	cout << b1 - a1 - 1 << '\n';
	return 0;
}
