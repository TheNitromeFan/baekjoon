#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	cout << (char)('E' + 'I' - s[0]);
	cout << (char)('S' + 'N' - s[1]);
	cout << (char)('T' + 'F' - s[2]);
	cout << (char)('J' + 'P' - s[3]);
	return 0;
}
