#include <iostream>
#include <string>

using namespace std;

string decode(string &alphabet, string &code, unsigned idx, int cur, int cnt){
	// cout << idx << ' ' << cur << '\n';
	if(idx == code.length()){
		if(cur >= 0 && cur < 26){
			return string(1, alphabet[cur]);
		}else{
			return string(100, 'A');
		}
	}else if(cur == -1){
		return decode(alphabet, code, idx + 1, code[idx] - '0', cnt + 1);
	}else if(10 * cur + code[idx] - '0' >= 26 || cnt == 2){
		return string(1, alphabet[cur]) + decode(alphabet, code, idx, -1, 0);
	}
	string s1 = decode(alphabet, code, idx + 1, 10 * cur + code[idx] - '0', cnt + 1);
	string s2 = string(1, alphabet[cur]) + decode(alphabet, code, idx, -1, 0);
	if(s1.length() < s2.length()){
		return s1;
	}else if(s1.length() > s2.length()){
		return s2;
	}else if(s1 > s2){
		return s1;
	}else{
		return s2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int problem = 0;
	while(true){
		string alphabet;
		cin >> alphabet;
		if(alphabet == "#"){
			break;
		}
		++problem;
		cout << "Problem " << problem << '\n';
		while(true){
			string code;
			cin >> code;
			if(code == "0"){
				break;
			}
			cout << decode(alphabet, code, 0, -1, 0) << '\n';
		}
		cout << '\n';
	}
	return 0;
}
