#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	string parens;
	cin >> parens;
	stack<char> st;
	unsigned ans = 0;
	for(unsigned i = 0; i < parens.length(); ++i){
		if(parens[i] == '('){
			st.push(i);
		}
		else{
			st.pop();
			if(parens[i - 1] == '('){
				ans += st.size();
			}else{
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
