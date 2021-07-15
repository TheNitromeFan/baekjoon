#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string::size_type len = s.length();
	s.insert(s.begin() + len / 2, ' ');
	cout << s << '\n';
	return 0;
}
