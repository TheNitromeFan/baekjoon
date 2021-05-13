#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	unsigned idx = 0;
	int cnt = 0;
	while(idx < s.length()){
		if(s[idx] == 'M'){
			++cnt;
		}else{
			cout << 5;
			while(cnt > 0){
				cout << 0;
				--cnt;
			}
		}
		++idx;
	}
	if(cnt > 0){
		while(cnt > 0){
			cout << 1;
			--cnt;
		}
	}
	cout << '\n';
	idx = 0;
	while(idx < s.length()){
		if(s[idx] == 'M'){
			++cnt;
		}else{
			if(cnt > 0){
				cout << 1;
				--cnt;
				while(cnt > 0){
					cout << 0;
					--cnt;
				}
			}
			cout << 5;
		}
		++idx;
	}
	if(cnt > 0){
		cout << 1;
		--cnt;
		while(cnt > 0){
			cout << 0;
			--cnt;
		}
	}
	return 0;
}
