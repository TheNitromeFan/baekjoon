#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	reverse(t.begin(), t.end());
	stack<char> st;
	for(unsigned i = 0; i < s.length(); ++i){
		st.push(s[i]);
		if(s[i] == t[0]){
			string cmp = "";
			for(unsigned j = 0; !st.empty() && j < t.length(); ++j){
				cmp += st.top();
				st.pop();
			}
			if(cmp == t){
				continue;
			}
			reverse(cmp.begin(), cmp.end());
			for(unsigned j = 0; j < cmp.length(); ++j){
				st.push(cmp[j]);
			}
		}
	}
	string ans = "";
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
