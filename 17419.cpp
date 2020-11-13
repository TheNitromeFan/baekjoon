#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == '1'){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
