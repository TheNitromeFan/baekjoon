#include <iostream>
#include <string>

using namespace std;

int holes(char c){
	int ret = 0;
	switch(c){
		case 'A':
		case 'D':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
			ret = 1;
			break;
		case 'B':
			ret = 2;
			break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int i = 0; i < n; ++i){
		getline(cin, line);
		int ans = 0;
		for(char c : line){
			ans += holes(c);
		}
		cout << ans << '\n';
	}
	return 0;
}
