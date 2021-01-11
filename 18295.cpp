#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<string> s;
	for(int i = 0; i < n; ++i){
		string x;
		cin >> x;
		s.insert(x);
	}
	int ans = 0;
	while(true){
		string str = to_string(ans);
		if(s.find(str) == s.end()){
			break;
		}
		++ans;
	}
	cout << ans;
	return 0;
}
