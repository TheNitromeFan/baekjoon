#include <iostream>
#include <string>

using namespace std;

int main(){
	char opt;
	string line;
	cin >> opt >> line;
	if(opt == 'E'){
		int cnt = 1;
		char cur = line[0];
		for(unsigned i = 1; i < line.length(); ++i){
			if(line[i] != cur){
				cout << cur << cnt;
				cnt = 1;
				cur = line[i];
			}else{
				++cnt;
			}
		}
		cout << cur << cnt;
	}else{
		for(unsigned i = 0; i < line.length(); i += 2){
			char c = line[i];
			int n = line[i + 1] - '0';
			for(int j = 0; j < n; ++j){
				cout << c;
			}
		}
	}
	return 0;
}
