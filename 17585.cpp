#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool> eval(n);
	for(int i = 0; i < n; ++i){
		char x;
		cin >> x;
		eval[i] = (x == 'T');
	}
	char c;
	stack<bool> st;
	while(cin >> c){
		if(c >= 'A' && c <= 'Z'){
			st.push(eval[c - 'A']);
		}else if(c == '*'){
			bool b = st.top();
			st.pop();
			bool a = st.top();
			st.pop();
			st.push(a && b);
		}else if(c == '+'){
			bool b = st.top();
			st.pop();
			bool a = st.top();
			st.pop();
			st.push(a || b);
		}else{
			bool a = st.top();
			st.pop();
			st.push(!a);
		}
	}
	cout << (st.top() ? 'T' : 'F');
	return 0;
}
