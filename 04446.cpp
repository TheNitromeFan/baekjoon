#include <iostream>
#include <string>

using namespace std;

bool vowel(char c){
	bool ret = false;
	switch(c){
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			ret = true;
			break;
	}
	return ret;
}

int main(){
	string consonants_lower = "bkxznhdcwgpvjqtsrlmf", vowels_lower = "aiyeou";
	string consonants_upper = "BKXZNHDCWGPVJQTSRLMF", vowels_upper = "AIYEOU";
	string line;
	while(getline(cin, line)){
		for(char c : line){
			if(c >= 'A' && c <= 'Z'){
				if(vowel(c)){
					cout << vowels_upper[(vowels_upper.find(c) + 3) % 6];
				}else{
					cout << consonants_upper[(consonants_upper.find(c) + 10) % 20];
				}
			}else if(c >= 'a' && c <= 'z'){
				if(vowel(c)){
					cout << vowels_lower[(vowels_lower.find(c) + 3) % 6];
				}else{
					cout << consonants_lower[(consonants_lower.find(c) + 10) % 20];
				}
			}else{
				cout << c;
			}
		}
		cout << '\n';
	}
	return 0;
}
