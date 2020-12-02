#include <iostream>
#include <string>

using namespace std;

int val(char c){
	if(c == ' '){
		return 0;
	}else{
		return c - 'a' + 1;
	}
}

char chr(int v){
	if(v == 0){
		return ' ';
	}else{
		return 'a' + v - 1;
	}
}

string convert(string &text){
	string ret = "";
	if(text[0] == 'e'){
		ret += text[2];
		for(unsigned i = 3; i < text.length(); ++i){
			ret += chr((val(ret[ret.length() - 1]) + val(text[i])) % 27);
		}
	}else{
		ret += text[2];
		for(unsigned i = 3; i < text.length(); ++i){
			ret += chr((val(text[i]) - val(text[i - 1]) + 27) % 27);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string text;
	getline(cin, text);
	for(int a0 = 0; a0 < t; ++a0){
		getline(cin, text);
		cout << convert(text) << '\n';
	}
	return 0;
}
