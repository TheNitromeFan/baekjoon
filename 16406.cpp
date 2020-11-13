#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	unsigned k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	unsigned n = a.length();
	unsigned x = 0;
	for(unsigned i = 0; i < n; ++i){
		if(a[i] == b[i]){
			++x;
		}
	}
	cout << (min(k, x) + min(n - k, n - x));
	return 0;
}
