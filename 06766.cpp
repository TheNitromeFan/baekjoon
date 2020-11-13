#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main(){
	int k;
	cin >> k;
	string word;
	cin >> word;
	for(unsigned i = 0; i < word.length(); ++i){
		unsigned shift = (3 * (i+1) + k) % 26;
		char c = word[i] - shift;
		if(c < 'A'){
			c += 26;
		}
		cout << c;
	}
	return 0;
}
