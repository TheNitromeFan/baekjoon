#include <iostream>
#include <string>

using namespace std;

string digits[10] = {"**** ** ** ****", "  *  *  *  *  *", "***  *****  ***",
					"***  ****  ****", "* ** ****  *  *", "****  ***  ****",
					"****  **** ****", "***  *  *  *  *", "**** ***** ****",
					"**** ****  ****"};

int digit(string s){
	for(int i = 0; i < 10; ++i){
		if(digits[i] == s){
			return i;
		}
	}
	return -1;
}

bool bomb(string s[5]){
	int n = 0;
	for(unsigned block = 0; block + 3 <= s[0].length(); block += 4){
		string d;
		for(unsigned i = 0; i < 5; ++i){
			for(unsigned j = 0; j < 3; ++j){
				d += s[i][block + j];
			}
		}
		int k = digit(d);
		if(k == -1){
			return false;
		}
		n *= 10;
		n += k;
	}
	return n % 6 == 0;
}

int main(){
	string input[5];
	for(int i = 0; i < 5; ++i){
		getline(cin, input[i]);
	}
	cout << (bomb(input) ? "BEER!!" : "BOOM!!");
	return 0;
}
