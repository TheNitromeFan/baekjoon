#include <iostream>
#include <string>

using namespace std;

int main(){
	string caesar;
	cin >> caesar;
	for(char letter : caesar){
		char c = letter - 3;
		if(c < 'A'){
			c += 26;
		}
		cout << c;
	}
	return 0;
}
