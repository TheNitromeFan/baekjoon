#include <iostream>
#include <string>
#include <stack>

using namespace std;

int val(char c){
	if(c == 'H'){
		return 1;
	}else if(c == 'C'){
		return 12;
	}else{
		return 16;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string mol;
	cin >> mol;
	stack<string> s;
	for(char c : mol){
		if(c == ')'){
			int cur = 0;
			while(s.top() != "("){
				if(s.top() == "C" || s.top() == "H" || s.top() == "O"){
					cur += val(s.top()[0]);
				}else{
					cur += stoi(s.top());
				}
				s.pop();
			}
			s.pop();
			s.push(to_string(cur));
		}else if(c >= '1' && c <= '9'){
			int cur = 0;
			if(s.top() == "C" || s.top() == "H" || s.top() == "O"){
				cur = val(s.top()[0]);
			}else{
				cur = stoi(s.top());
			}
			s.pop();
			cur *= c - '0';
			s.push(to_string(cur));
		}else{
			s.push(string(1, c));
		}
	}
	int ans = 0;
	while(!s.empty()){
		if(s.top() == "C" || s.top() == "H" || s.top() == "O"){
			ans += val(s.top()[0]);
		}else{
			ans += stoi(s.top());
		}
		s.pop();
	}
	cout << ans;
	return 0;
}
