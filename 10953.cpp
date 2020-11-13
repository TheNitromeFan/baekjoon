#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		int a = s[0] - '0', b = s[2] - '0';
		cout << a+b << endl;
	}
	return 0;
}
