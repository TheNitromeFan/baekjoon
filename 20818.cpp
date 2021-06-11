#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string necklace;
	cin >> necklace;
	string::size_type len = necklace.length();
	string s = necklace + necklace;
	int cnt = 0;
	for(string::size_type i = 0; i < len / 2; ++i){
		if(s[i] == 'B'){
			++cnt;
		}
	}
	int max_cnt = cnt;
	for(string::size_type i = 0; i < len; ++i){
		if(s[i + len / 2] == 'B'){
			++cnt;
		}
		if(s[i] == 'B'){
			--cnt;
		}
		max_cnt = max(max_cnt, cnt);
	}
	cout << max_cnt;
	return 0;
}
