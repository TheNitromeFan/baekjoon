#include <iostream>
#include <string>

using namespace std;

int main(){
	string text;
	cin >> text;
	int days = 0;
	for(unsigned i = 0; i < text.length(); ++i){
		if(!((i % 3 == 0 && text[i] == 'P') || (i % 3 == 1 && text[i] == 'E') || (i % 3 == 2 && text[i] == 'R'))){
			++days;
		}
	}
	cout << days;
	return 0;
}
