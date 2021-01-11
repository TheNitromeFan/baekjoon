#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		unsigned n;
		cin >> n;
		if(n == 0){
			break;
		}
		string text;
		getline(cin, text);
		getline(cin, text);
		string plain;
		for(char c : text){
			if(c == ' '){
				continue;
			}
			plain += toupper(c);
		}
		string code(plain.length(), ' ');
		unsigned idx = 0;
		unsigned i = 0;
		while(true){
			code[idx] = plain[i];
			idx += n;
			++i;
			if(i == plain.length()){
				break;
			}
			if(idx >= plain.length()){
				idx = 0;
				while(code[idx] != ' '){
					++idx;
				}
			}
		}
		cout << code << '\n';
	}
	return 0;
}
