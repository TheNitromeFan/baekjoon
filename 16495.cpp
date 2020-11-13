#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	long long ans = 0;
	for(char c : s){
		ans = ans * 26 + (c - 'A') + 1;
	}
	cout << ans;
	return 0;
}
