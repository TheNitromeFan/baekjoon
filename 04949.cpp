#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_balanced(string &s){
	stack<char> parens;
	for(char c : s){
		if(c == '(' || c == '['){
			parens.push(c);
		}else if(c == ']'){
			if(parens.empty()){
				return false;
			}
			char tmp = parens.top();
			if(tmp == '('){
				return false;
			}
			parens.pop();
		}else if(c == ')'){
			if(parens.empty()){
				return false;
			}
			char tmp = parens.top();
			if(tmp == '['){
				return false;
			}
			parens.pop();
		}
	}
	return parens.empty();
}

int main(){
	while(true){
		string input;
		getline(cin, input);
		if(input.length() == 1 && input[0] == '.'){
			break;
		}
		if(is_balanced(input)){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}
	}
	return 0;
}
