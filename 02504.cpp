#include <iostream>
#include <vector>
#include <string>

using namespace std;

int resolve(vector<int> &s, char wrong, char right, int multiplier){
	int res = 0;
	while(!s.empty()){
		if(s[s.size()-1] == wrong){
			return -1;
		}else if(s[s.size()-1] == right){
			s.pop_back();
			res *= multiplier;
			s.push_back(res + '0');
			break;
		}else{
			res += s[s.size()-1] - '0';
			s.pop_back();
		}
	}
	return res;
}

int main(){
	string parentheses;
	cin >> parentheses;
	vector<int> stack;
	int result = 0;
	for(char c : parentheses){
		if(c == '('){
			stack.push_back('(');
		}else if(c == '['){
			stack.push_back('[');
		}else if(c == ')'){
			if(!stack.empty() && stack[stack.size()-1] == '('){
				stack.pop_back();
				stack.push_back('2');
			}else{
				int result = resolve(stack, '[', '(', 2);
			}
		}else if(c = ']'){
			if(!stack.empty() && stack[stack.size()-1] == '['){
				stack.pop_back();
				stack.push_back('3');
			}else{
				int result = resolve(stack, '(', '[', 3);
			}
		}
		if(result == -1){
			cout << 0 << endl;
			return 0;
		}
	}
	int total = 0;
	while(!stack.empty()){
		if(stack[stack.size()-1] == '(' || stack[stack.size()-1] == '['){
			cout << 0 << endl;
			return 0;
		}
		total += stack[stack.size()-1] - '0';
		stack.pop_back();
	}
	cout << total << endl;
	return 0;
}
