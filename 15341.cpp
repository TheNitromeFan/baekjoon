#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string card;
		for(int a0 = 0; a0 < 4; ++a0){
			string num;
			cin >> num;
			card += num;
		}
		if(card == "0000000000000000"){
			break;
		}
		int sum = 0;
		for(int i = 0; i < 16; ++i){
			int digit = card[i] - '0';
			if(i % 2 == 0){
				digit *= 2;
			}
			if(digit > 9){
				digit -= 9;
			}
			sum += digit;
		}
		cout << (sum % 10 == 0 ? "Yes" : "No") << '\n';
	}
	return 0;
}
