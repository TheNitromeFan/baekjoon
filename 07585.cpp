#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool valid(string line){
	stack<char> s;
	for(char c : line){
		if(!s.empty() && ((c == '}' && s.top() == '{') || (c == ')' && s.top() == '(') || (c == ']' && s.top() == '['))){
			s.pop();
		}else if(c == '}' || c == ')' || c == ']'){
			return false;
		}else if(c == '{' || c == '(' || c == '['){
			s.push(c);
		}
	}
	return s.empty();
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
		cout << (valid(line) ? "Legal" : "Illegal") << '\n';
	}
	return 0;
}
