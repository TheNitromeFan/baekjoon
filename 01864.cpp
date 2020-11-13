#include <iostream>
#include <string>

using namespace std;

int code(char c){
	int ret = 10;
	switch(c){
		case '-':
			ret = 0;
			break;
		case '\\':
			ret = 1;
			break;
		case '(':
			ret = 2;
			break;
		case '@':
			ret = 3;
			break;
		case '?':
			ret = 4;
			break;
		case '>':
			ret = 5;
			break;
		case '&':
			ret = 6;
			break;
		case '%':
			ret = 7;
			break;
		case '/':
			ret = -1;
			break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		cin >> line;
		if(line == "#"){
			break;
		}
		int ans = 0;
		for(char c : line){
			ans *= 8;
			ans += code(c);
		}
		cout << ans << '\n';
	}
	return 0;
}
