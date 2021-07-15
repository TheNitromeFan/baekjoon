#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p, d;
	cin >> n >> p >> d;
	string s;
	cin >> s;
	s += s;
	int sleep = 0;
	for(int i = 0; i < p - 1; ++i){
		if(s[i] == 'Z'){
			++sleep;
		}
	}
	int ans = 0;
	for(int i = p - 1, j = 0; j < n; ++i, ++j){
		if(s[i] == 'Z'){
			++sleep;
		}
		if(sleep < d){
			++ans;
		}
		if(s[j] == 'Z'){
			--sleep;
		}
	}
	cout << ans << '\n';
	return 0;
}
