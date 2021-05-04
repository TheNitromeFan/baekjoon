#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	string s;
	cin >> s;
	unsigned prev = 0;
	while(s[prev] == '#'){
		++prev;
	}
	unsigned cur = prev + 1;
	unsigned ans = n;
	while(cur < n){
		while(cur < n && s[cur] == '#'){
			++cur;
		}
		if(cur < n && ans > cur - prev){
			ans = cur - prev;
		}
		prev = cur;
		++cur;
	}
	cout << ans - 1;
	return 0;
}
