#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::string;
using std::sort;
using std::greater;

int main(){
	string s;
	cin >> s;
	sort(s.begin(), s.end(), greater<char>());
	cout << s;
	return 0;
}
