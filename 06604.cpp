#include <iostream>
#include <stack>
#include <utility>
#include <map>

using namespace std;

int main(){
	int n;
	cin >> n;
	map<char, pair<int, int>> matrices;
	for(int i = 0; i < n; ++i){
		char matrix;
		int rows, columns;
		cin >> matrix >> rows >> columns;
		matrices[matrix] = make_pair(rows, columns);
	}
	string expression;
	while(cin >> expression){
		int ans = 0;
		stack<pair<int, int>> st;
		bool error = false;
		for(char c : expression){
			if(c == ')'){
				pair<int, int> b = st.top();
				st.pop();
				pair<int, int> a = st.top();
				st.pop();
				if(a.second == b.first){
					ans += a.first * a.second * b.second;
					st.pop();
					st.push(make_pair(a.first, b.second));
				}else{
					cout << "error\n";
					error = true;
					break;
				}
			}else if(c == '('){
				st.push(make_pair(0, 0));
			}else{
				st.push(matrices[c]);
			}
		}
		if(!error){
			cout << ans << '\n';
		}
	}
	return 0;
}
