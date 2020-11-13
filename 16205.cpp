#include <iostream>
#include <string>

using namespace std;

string change_case(string s, int i, int j){
	string ret;
	if(i == j){
		ret = s;
	}else if(i == 1 && j == 2){
		for(char c : s){
			if(c >= 'A' && c <= 'Z'){
				ret += '_';
				c += 'a' - 'A';
			}
			ret += c;
		}
	}else if(i == 1){
		ret = s;
		ret[0] -= 'a' - 'A';
	}else if(i == 2 && j == 1){
		bool cap = false;
		for(char c : s){
			if(c == '_'){
				cap = true;
				continue;
			}else if(cap){
				c -= 'a' - 'A';
			}
			ret += c;
			cap = false;
		}
	}else if(i == 2){
		bool cap = true;
		for(char c : s){
			if(c == '_'){
				cap = true;
				continue;
			}else if(cap){
				c -= 'a' - 'A';
			}
			ret += c;
			cap = false;
		}
	}else if(i == 3 && j == 1){
		ret = s;
		ret[0] += 'a' - 'A';
	}else{
		s[0] += 'a' - 'A';
		for(char c : s){
			if(c >= 'A' && c <= 'Z'){
				ret += '_';
				c += 'a' - 'A';
			}
			ret += c;
		}
	}
	return ret;
}

int main(){
	int n;
	string s;
	cin >> n >> s;
	for(int i = 1; i <= 3; ++i){
		cout << change_case(s, n, i) << '\n';
	}
	return 0;
}
