#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char mirror(char c){
	switch(c){
		case 'b':
			return 'd';
		case 'd':
			return 'b';
		case 'p':
			return 'q';
		case 'q':
			return 'p';
		case 'i':
		case 'o':
		case 'v':
		case 'w':
		case 'x':
			return c;
		default:
			return 'X';
	}
}

string mirror_image(string s){
	string ret = "";
	for(char c : s){
		char m = mirror(c);
		if(m == 'X'){
			return "INVALID";
		}
		ret += m;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string s;
		cin >> s;
		if(s == "#"){
			break;
		}
		cout << mirror_image(s) << '\n';
	}
	return 0;
}
