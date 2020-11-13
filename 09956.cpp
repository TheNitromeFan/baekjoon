#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool letter(char c){
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "#"){
			break;
		}
		unsigned idx = 0;
		while(idx < line.length()){
			if(line[idx] != ' '){
				string symbols, word;
				vector<bool> cap, letters;
				while(idx < line.length() && line[idx] != ' '){
					symbols += line[idx];
					if(letter(line[idx])){
						letters.push_back(true);
						if(line[idx] >= 'A' && line[idx] <= 'Z'){
							cap.push_back(true);
							word += line[idx] - 'A' + 'a';
						}else{
							cap.push_back(false);
							word += line[idx];
						}
					}else{
						letters.push_back(false);
					}
					++idx;
				}
				reverse(word.begin(), word.end());
				unsigned letter_idx = 0;
				for(unsigned i = 0; i < symbols.length(); ++i){
					char c = symbols[i];
					if(letter(c)){
						c = word[letter_idx];
						if(cap[letter_idx]){
							c -= 'a' - 'A';
						}
						++letter_idx;
					}
					cout << c;
				}
			}else{
				cout << line[idx];
				++idx;
			}
		}
		cout << '\n';
	}
	return 0;
}
