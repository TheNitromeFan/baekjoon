#include <iostream>
#include <string>

using namespace std;

bool is_java(string s){
	if(!(s[0] >= 'a' && s[0] <= 'z')){
		return false;
	}
	for(char c : s){
		if(c == '_'){
			return false;
		}
	}
	return true;
}

bool is_c(string s){
	for(unsigned i = 0; i < s.length(); ++i){
		if((s[i] >= 'A' && s[i] <= 'Z')
		|| (s[i] == '_' && (i == 0 || i + 1 == s.length() || s[i - 1] == '_' || s[i + 1] == '_'))){
			return false;
		}
	}
	return true;
}

string java_to_c(string s){
	string ret = "";
	for(char c : s){
		if(c >= 'A' && c <= 'Z'){
			ret += '_';
			char tmp = c - 'A' + 'a';
			ret += tmp;
		}else{
			ret += c;
		}
	}
	return ret;
}

string c_to_java(string s){
	string ret = "";
	bool upper = false;
	for(char c : s){
		if(c == '_'){
			upper = true;
		}else if(upper){
			char tmp = c - 'a' + 'A';
			ret += tmp;
			upper = false;
		}else{
			ret += c;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string id;
	cin >> id;
	if(is_java(id)){
		cout << java_to_c(id);
	}else if(is_c(id)){
		cout << c_to_java(id);
	}else{
		cout << "Error!";
	}
	return 0;
}
