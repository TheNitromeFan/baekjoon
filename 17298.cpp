#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> ans(n);
	stack<int> s;
	for(int i = n - 1; i >= 0; --i){
		while(!s.empty() && s.top() <= a[i]){
			s.pop();
		}
		if(!s.empty()){
			ans[i] = s.top();
		}else{
			ans[i] = -1;
		}
		s.push(a[i]);
	}
	for(int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
	return 0;
}
