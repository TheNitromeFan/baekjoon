#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string s;
		cin >> s;
		if(s == "END"){
			break;
		}
		int idx = (int)s.length() - 1;
		while(idx >= 0 && s[idx] == '0'){
			--idx;
		}
		if(!(idx == 0 && s[idx] == '1')){
			--s[idx];
		}else{
			s = "0";
		}
		cout << s << '\n';
	}
	return 0;
}
