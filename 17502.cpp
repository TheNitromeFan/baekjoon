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
	for(unsigned i = 0; i <= n / 2; ++i){
		unsigned j = n - 1 - i;
		if(s[i] == '?' && s[j] != '?'){
			s[i] = s[j];
		}else if(s[i] != '?' && s[j] == '?'){
			s[j] = s[i];
		}else if(s[i] == '?' && s[j] == '?'){
			s[i] = 'a';
			s[j] = 'a';
		}
	}
	cout << s;
	return 0;
}
