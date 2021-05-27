#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int zeroes = 0, ones = 0;
	for(char c : s){
		if(c == '0'){
			++zeroes;
		}else{
			++ones;
		}
	}
	vector<bool> marked(s.length());
	for(unsigned i = 0; i < s.length(); ++i){
		if(s[i] == '1'){
			marked[i] = true;
			ones -= 2;
			if(ones == 0){
				break;
			}
		}
	}
	for(unsigned i = s.length() - 1; i > 0; --i){
		if(s[i] == '0'){
			marked[i] = true;
			zeroes -= 2;
			if(zeroes == 0){
				break;
			}
		}
	}
	for(unsigned i = 0; i < s.length(); ++i){
		if(!marked[i]){
			cout << s[i];
		}
	}
	return 0;
}
