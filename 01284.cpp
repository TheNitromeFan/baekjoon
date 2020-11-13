#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string number;
	while(true){
		cin >> number;
		if(number == "0"){
			break;
		}
		unsigned len = number.length() + 1;
		for(char digit : number){
			switch(digit){
				case '0':
					len += 4;
					break;
				case '1':
					len += 2;
					break;
				default:
					len += 3;
					break;
			}
		}
		cout << len << '\n';
	}
	return 0;
}
