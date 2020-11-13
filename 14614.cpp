#include <iostream>
#include <string>

using namespace std;

int main(){
	int a, b;
	string c;
	cin >> a >> b >> c;
	cout << ((c[c.length() - 1] - '0') % 2 ? (a ^ b) : a);
	return 0;
}
