#include <iostream>
#include <string>

using namespace std;

bool vowel(char c){
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
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
		if(line == "#"){
			break;
		}
		int con = 0, v = 0;
		for(char c : line){
			if(vowel(c)){
				++v;
			}else if(c != ' '){
				++con;
			}
		}
		cout << con << ' ' << v << '\n';
	}
	return 0;
}
