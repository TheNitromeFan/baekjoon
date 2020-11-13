#include <iostream>
#include <string>

using namespace std;

int main(){
	string num;
	cin >> num;
	bool cute = true;
	for(int i = 1; i < num.length() - 1; ++i){
		if(2 * (num[i] - '0') != (num[i-1] - '0') + (num[i+1] - '0')){
			cute = false;
			break;
		}
	}
	cout << (cute ? "?(?????)?..¡Æ¢½ ²î¿ä¹Ì!!" : "ÈïÄ©»×!! <(£þ ? £þ)>");
	return 0;
}
