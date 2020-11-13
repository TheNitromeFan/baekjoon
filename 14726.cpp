#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string card;
		cin >> card;
		int sum = 0;
		for(int j = 0; j < 16; ++j){
			int digit = card[j] - '0';
			if(j % 2 == 0){
				digit *= 2;
				if(digit >= 10){
					digit = digit / 10 + digit % 10;
				}
			}
			sum += digit;
		}
		cout << ((sum % 10 == 0) ? 'T' : 'F') << '\n';
	}
	return 0;
}
