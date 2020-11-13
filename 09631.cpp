#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		long long cnt = 1;
		unsigned j = 0;
		while(j < s.length()){
			if(s[j] != '?'){
				++j;
				continue;
			}
			unsigned j1 = (int)j;
			while(j1 > 0 && s[j1] == '?'){
				--j1;
			}
			while(j < s.length() && s[j] == '?'){
				++j;
			}
			if(j1 == 0 && s[0] == '?');
			else if(j == s.length());
			else if(s[j1] == s[j]);
			else{
				cnt *= (long long)(j - j1);
				cnt %= MOD;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
