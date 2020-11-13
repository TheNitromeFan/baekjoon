#include <iostream>
#include <string>

using namespace std;

bool vowel(char c){
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "#"){
			break;
		}
		int ans = 0;
		for(char c : line){
			if(vowel(c)){
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
