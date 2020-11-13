#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> keyboard = {"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
	map<char, char> shift;
	for(string s : keyboard){
		for(unsigned i = 1; i < s.length(); ++i){
			shift[s[i]] = s[i - 1];
		}
	}
	shift[' '] = ' ';
	string line;
	while(getline(cin, line)){
		for(char c : line){
			cout << shift[c];
		}
		cout << '\n';
	}
	return 0;
}
