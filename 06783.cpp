#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main(){
	int n;
	cin >> n;
	int t = 0, s = 0;
	string line;
	getline(cin, line);
	for(int a0 = 0; a0 < n; ++a0){
		getline(cin, line);
		for(char c : line){
			if(c == 'T' || c == 't'){
				++t;
			}else if(c == 'S' || c == 's'){
				++s;
			}
		}
	}
	cout << ((t > s) ? "English" : "French") << '\n';
	return 0;
}
