#include <iostream>
#include <string>

using namespace std;

int main(){
	string code;
	cin >> code;
	unsigned nop = 0;
	for(unsigned i = 0; i < code.length(); ++i){
		unsigned pos = i + nop;
		if(code[i] >= 'A' && code[i] <= 'Z' && pos % 4 != 0){
			nop += (4 - pos % 4);
		}
	}
	cout << nop;
	return 0;
}
