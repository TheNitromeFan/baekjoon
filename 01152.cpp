#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main(){
	string s;
	int count = 0;
	while(cin >> s)
		++count;
	cout << count;
	return 0;
}
