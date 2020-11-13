#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string word;
		cin >> word;
		string ans = word;
		switch(word[word.length() - 1]){
			case 'a':
			case 'o':
			case 'u':
				ans += 's';
				break;
			case 'i':
			case 'y':
				ans = word.substr(0, word.length() - 1) + "ios";
				break;
			case 'l':
			case 'r':
			case 'v':
				ans += "es";
				break;
			case 'n':
				ans = word.substr(0, word.length() - 1) + "anes";
				break;
			case 't':
			case 'w':
				ans += "as";
				break;
			case 'e':
				if(word[word.length() - 2] == 'n'){
					ans = word.substr(0, word.length() - 2) + "anes";
				}else{
					ans += "us";
				}
				break;
			default:
				ans += "us";
				break;
		}
		cout << ans << '\n';
	}
	return 0;
}
