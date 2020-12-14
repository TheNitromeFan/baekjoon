#include <iostream>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		stack<int> s;
		int cnt = 0;
		for(int j = 0; j < 12; ++j){
			int x;
			cin >> x;
			while(!s.empty() && s.top() > x){
				s.pop();
			}
			if(!s.empty() && s.top() < x){
				++cnt;
				s.push(x);
			}else if(s.empty()){
				s.push(x);
			}
		}
		cout << k << ' ' << cnt << '\n';
	}
	return 0;
}
