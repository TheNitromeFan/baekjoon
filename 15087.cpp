#include <iostream>
#include <string>

using namespace std;

int main(){
	string mess;
	cin >> mess;
	string ans = mess.substr(0, mess.length() / 2);
	string key = mess.substr(mess.length() / 2, mess.length() / 2);
	int rot;
	rot = 0;
	for(char c : ans){
		rot = (rot + c - 'A') % 26;
	}
	for(char &c : ans){
		c += rot;
		if(c > 'Z'){
			c -= 26;
		}
	}
	rot = 0;
	for(char c : key){
		rot = (rot + c - 'A') % 26;
	}
	for(char &c : key){
		c += rot;
		if(c > 'Z'){
			c -= 26;
		}
	}
	for(unsigned i = 0; i < ans.length(); ++i){
		ans[i] += key[i] - 'A';
		if(ans[i] > 'Z'){
			ans[i] -= 26;
		}
	}
	cout << ans;
	return 0;
}
