#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int reg = 0;
	stack<int> s;
	vector<string> inst(n);
	vector<int> arg(n);
	for(int j = 0; j < n; ++j){
		cin >> inst[j];
		if(inst[j] == "PUSH" || inst[j] == "IFZERO"){
			cin >> arg[j];
		}
	}
	int i = 0;
	while(true){
		string com = inst[i];
		if(com == "PUSH"){
			s.push(arg[i]);
		}else if(com == "STORE"){
			reg = s.top();
			s.pop();
		}else if(com == "LOAD"){
			s.push(reg);
		}else if(com == "PLUS"){
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push(x + y);
		}else if(com == "TIMES"){
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push(x * y);
		}else if(com == "IFZERO"){
			int x = s.top();
			s.pop();
			if(x == 0){
				i = arg[i] - 1;
			}
		}else if(com == "DONE"){
			cout << s.top();
			break;
		}
		// cout << i << ' ' << s.size() << ' ' << "reg: " << reg << '\n';
		++i;
	}
	return 0;
}
