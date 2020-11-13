#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main(){
	char s[200];
	scanf("%s", s);
	int n = strlen(s);
	stack<char> st;
	for(int i = 0; i < n; ++i){
		if(s[i] == '('){
			st.push(s[i]);
		}else if(s[i] == ')'){
			while(!st.empty()){
				char tmp = st.top();
				st.pop();
				if(tmp == '('){
					break;
				}
				printf("%c", tmp);
			}
		}else if(s[i] == '*' || s[i] == '/'){
			while(!st.empty()){
				char tmp = st.top();
				if(tmp == '(' || tmp == '+' || tmp == '-'){
					break;
				}
				st.pop();
				printf("%c", tmp);
			}
			st.push(s[i]);
		}else if(s[i] == '+' || s[i] == '-'){
			while(!st.empty()){
				char tmp = st.top();
				if(tmp == '('){
					break;
				}
				st.pop();
				printf("%c", tmp);
			}
			st.push(s[i]);
		}else{
			printf("%c", s[i]);
		}
	}
	while(!st.empty()){
		printf("%c", st.top());
		st.pop();
	}
	return 0;
}
