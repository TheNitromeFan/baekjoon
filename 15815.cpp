#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> st;
	string s;
	cin >> s;
	for(char c : s){
		int a, b;
		switch(c){
			case '+':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(a + b);
				break;
			case '-':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(a - b);
				break;
			case '*':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(a * b);
				break;
			case '/':
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				st.push(a / b);
				break;
			default:
				st.push(c - '0');
		}
	}
	cout << st.top();
	return 0;
}
