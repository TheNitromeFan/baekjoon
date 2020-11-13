#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	string p;
	cin >> p;
	stack<char> s;
	unsigned ans = 0;
	for(char x : p){
		if(x == '('){
			s.push(x);
		}else if(!s.empty()){
			s.pop();
		}else{
			++ans;
		}
	}
	ans += s.size();
	cout << ans;
	return 0;
}
