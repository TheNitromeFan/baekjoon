#include <iostream>
#include <string>

using namespace std;

string percent(char c){
	string ret;
	switch(c){
		case ' ':
			ret = "%20";
			break;
		case '!':
			ret = "%21";
			break;
		case '$':
			ret = "%24";
			break;
		case '%':
			ret = "%25";
			break;
		case '(':
			ret = "%28";
			break;
		case ')':
			ret = "%29";
			break;
		case '*':
			ret = "%2a";
			break;
		default:
			ret += c;
			break;
	}
	return ret;
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
		for(char c : line){
			cout << percent(c);
		}
		cout << '\n';
	}
	return 0;
}
