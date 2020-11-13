#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	set<string> s;
	for(int i = 0; i < n; ++i){
		string x;
		cin >> x;
		s.insert(x);
	}
	int ans = 0;
	for(int j = 0; j < m; ++j){
		string x;
		cin >> x;
		if(s.find(x) != s.end()){
			++ans;
		}
	}
	cout << ans;
	return 0;
}
