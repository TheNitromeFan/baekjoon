#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int red1 = 0, blue1 = 0, red2 = 0, blue2 = 0;
	int idx = 0;
	while(idx < n && s[idx] == s[0]){
		++idx;
	}
	while(idx < n){
		if(s[idx] == 'R'){
			++red1;
		}else{
			++blue1;
		}
		++idx;
	}
	idx = n - 1;
	while(idx >= 0 && s[idx] == s[n - 1]){
		--idx;
	}
	while(idx >= 0){
		if(s[idx] == 'R'){
			++red2;
		}else{
			++blue2;
		}
		--idx;
	}
	cout << min(min(red1, blue1), min(red2, blue2)) << '\n';
	return 0;
}
