#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string n1, n2;
	cin >> n1 >> n2;
	unsigned l1 = n1.length(), l2 = n2.length();
	unsigned len = max(l1, l2);
	for(unsigned i = 0; i < len - l1; ++i){
		n1 = "0" + n1;
	}
	for(unsigned i = 0; i < len - l2; ++i){
		n2 = "0" + n2;
	}
	string ans;
	for(unsigned i = 0; i < len; ++i){
		ans = to_string((n1[len - 1 - i] - '0') + (n2[len - 1 - i] - '0')) + ans;
	}
	cout << ans;
	return 0;
}
