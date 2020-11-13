#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::string;

static char most_used_letter(const string &s){
	int counts[26] = {};
	for(char c : s){
		c = toupper(c);
		++counts[c - 'A'];
	}
	char most_letter = 'A';
	int most_count = 0;
	for(int i = 0; i < 26; ++i){
		if(counts[i] > most_count){
			most_count = counts[i];
			most_letter = i + 'A';
		}else if(counts[i] == most_count){
			most_letter = '?';
		}
	}
	return most_letter;
}

int main(){
	string input;
	cin >> input;
	cout << most_used_letter(input);
	return 0;
}
