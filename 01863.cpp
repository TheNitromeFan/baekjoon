#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<int, vector<int>> s;
	s.push(0);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		while(!s.empty() && s.top() > y){
			s.pop();
		}
		if(!(!s.empty() && s.top() == y)){
			++cnt;
			s.push(y);
		}
	}
	cout << cnt << '\n';
	return 0;
}
