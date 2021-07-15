#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	reverse(v.begin(), v.end());
	stack<int, vector<int>> s;
	vector<unsigned> ans;
	for(int i = 0; i < n; ++i){
		while(!s.empty() && s.top() <= v[i]){
			s.pop();
		}
		ans.push_back(s.size());
		s.push(v[i]);
	}
	reverse(ans.begin(), ans.end());
	for(unsigned x : ans){
		cout << x << ' ';
	}
	return 0;
}
