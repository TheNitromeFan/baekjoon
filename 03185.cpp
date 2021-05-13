#include <iostream>
#include <string>

using namespace std;

bool is_letter(char c){
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool is_vowel(char c){
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
	|| c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool has_unrevealed_vowels(string &answer, string &second_hint){
	for(unsigned i = 0; i < answer.length(); ++i){
		if(is_vowel(answer[i]) && !is_vowel(second_hint[i])){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string answer;
	getline(cin, answer);
	string first_hint = answer;
	int letter_count = 0;
	for(unsigned i = 0; i < answer.length(); ++i){
		if(is_letter(answer[i])){
			first_hint[i] = '.';
			++letter_count;
		}
	}
	cout << first_hint << '\n';
	int first_third = letter_count / 3, second_third = 2 * letter_count / 3;
	if(letter_count % 3 == 1){
		++second_third;
	}else if(letter_count % 3 == 2){
		++first_third;
	}
	string second_hint = first_hint;
	int revealed = 0;
	for(unsigned i = 0; i < answer.length() && revealed < first_third; ++i){
		if(is_letter(answer[i])){
			second_hint[i] = answer[i];
			++revealed;
		}
	}
	cout << second_hint << '\n';
	string third_hint = second_hint;
	if(has_unrevealed_vowels(answer, second_hint)){
		for(unsigned i = 0; i < answer.length(); ++i){
			if(is_vowel(answer[i])){
				third_hint[i] = answer[i];
			}
		}
	}else{
		revealed = 0;
		for(unsigned i = 0; i < answer.length() && revealed < second_third; ++i){
			if(is_letter(answer[i])){
				third_hint[i] = answer[i];
				++revealed;
			}
		}
	}
	cout << third_hint << '\n';
	return 0;
}
