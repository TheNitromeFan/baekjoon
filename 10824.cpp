#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::string;
using std::to_string;
using std::atoll;

int main(){
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(c) + to_string(d);
	long long sum = atoll(s1.c_str()) + atoll(s2.c_str());
	cout << sum;
	return 0;
}
