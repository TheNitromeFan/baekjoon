#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	unsigned n, m;
	cin >> n >> m;
	string ans;
	for(unsigned i = 0; i < n; ++i){
		ans += to_string(n);
	}
	for(unsigned idx = 0; idx < ans.length() && idx < m; ++idx){
		cout << ans[idx];
	}
	return 0;
}
