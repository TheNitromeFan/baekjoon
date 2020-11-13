#include <iostream>
#include <string>
#include <map>

using namespace std;

string decode[26] =  {".-",
					  "-...",
					  "-.-.",
					  "-..",
					  ".",
					  "..-.",
					  "--.",
					  "....",
					  "..",
					  ".---",
					  "-.-",
					  ".-..",
					  "--",
					  "-.",
					  "---",
					  ".--.",
					  "--.-",
					  ".-.",
					  "...",
					  "-",
					  "..-",
					  "...-",
					  ".--",
					  "-..-",
					  "-.--",
					  "--.."};

int main(){
	int t;
	cin >> t;
	map<string, char> morse;
	for(int i = 0; i < 26; ++i){
		morse[decode[i]] = i + 'A';
	}
	for(int a0 = 1; a0 <= t; ++a0){
		string s[5];
		for(int j = 0; j < 5; ++j){
			cin >> s[j];
		}
		cout << "Case " << a0 << ": ";
		for(int j = 0; j < 5; ++j){
			cout << morse[s[j]];
		}
		cout << '\n';
	}
	return 0;
}
