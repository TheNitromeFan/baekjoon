#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool acceptable(string &pass){
	bool found_vowel = false;
	for(int i = 0; i < pass.length(); ++i){
		if(is_vowel(pass[i])){
			found_vowel = true;
			break;
		}
	}
	if(!found_vowel){
		return false;
	}
	for(int i = 0; i + 2 < pass.length(); ++i){
		if((is_vowel(pass[i]) && is_vowel(pass[i+1]) && is_vowel(pass[i+2]))
		|| (!is_vowel(pass[i]) && !is_vowel(pass[i+1]) && !is_vowel(pass[i+2]))){
			return false;
		}
	}
	for(int i = 0; i + 1 < pass.length(); ++i){
		if(pass[i] == pass[i+1] && pass[i] != 'e' && pass[i] != 'o'){
			return false;
		}
	}
	return true;
}

int main(){
	while(true){
		string pass;
		cin >> pass;
		if(pass == "end"){
			break;
		}
		cout << "<" << pass << "> is " << (acceptable(pass) ? "" : "not ") << "acceptable.\n";
	}
	return 0;
}
