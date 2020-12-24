#include <iostream>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		stack<bool> s;
		for(int i = 0; i < n; ++i){
			char c;
			cin >> c;
			bool a, b;
			switch(c){
				case '0':
					s.push(false);
					break;
				case '1':
					s.push(true);
					break;
				case 'A':
					b = s.top();
					s.pop();
					a = s.top();
					s.pop();
					s.push(a && b);
					break;
				case 'R':
					b = s.top();
					s.pop();
					a = s.top();
					s.pop();
					s.push(a || b);
					break;
				case 'X':
					b = s.top();
					s.pop();
					a = s.top();
					s.pop();
					s.push(a ^ b);
					break;
				case 'N':
					a = s.top();
					s.pop();
					s.push(!a);
					break;
			}
		}
		cout << s.top() << '\n';
	}
	return 0;
}
