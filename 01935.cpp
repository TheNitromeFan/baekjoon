#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, double> values;
	for(int i = 0; i < n; ++i){
		double value;
		cin >> value;
		values['A' + i] = value;
	}
	stack<double> st;
	for(int j = 0; j < s.length(); ++j){
		if(s[j] >= 'A' && s[j] <= 'Z'){
			st.push(values[s[j]]);
		}else{
			double second = st.top();
			st.pop();
			double first = st.top();
			st.pop();
			if(s[j] == '+'){
				st.push(first + second);
			}else if(s[j] == '-'){
				st.push(first - second);
			}else if(s[j] == '*'){
				st.push(first * second);
			}else if(s[j] == '/'){
				st.push(first / second);
			}
		}
	}
	cout << fixed << setprecision(2) << st.top();
	return 0;
}
