#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	stack<char> st;
	bool is_tag = false;
	for(char c : s){
		if(c == '<'){
			while(!st.empty()){
				cout << st.top();
				st.pop();
			}
			is_tag = true;
		}else if(c == '>'){
			is_tag = false;
		}else if(c == ' '){
			while(!st.empty()){
				cout << st.top();
				st.pop();
			}
		}else if(!is_tag){
			st.push(c);
			continue;
		}
		cout << c;
	}
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
	return 0;
}
