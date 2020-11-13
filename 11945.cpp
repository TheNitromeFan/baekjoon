#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	return 0;
}
