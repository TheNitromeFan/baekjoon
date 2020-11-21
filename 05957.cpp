#include <iostream>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<int> a, b, c;
	for(int i = 0; i < n; ++i){
		a.push(n - i);
	}
	while(!a.empty() || !b.empty()){
		int ci, di;
		cin >> ci >> di;
		if(ci == 1){
			for(int j = 0; j < di; ++j){
				b.push(a.top());
				a.pop();
			}
		}else{
			for(int j = 0; j < di; ++j){
				c.push(b.top());
				b.pop();
			}
		}
	}
	for(int i = 0; i < n; ++i){
		cout << c.top() << '\n';
		c.pop();
	}
	return 0;
}
