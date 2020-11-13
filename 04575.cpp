#include <iostream>
#include <string>
#include <map>

using namespace std;

bool fridge(string s){
	map<char, bool> used;
	for(char a = 'A'; a <= 'Z'; ++a){
		used[a] = false;
	}
	for(char c : s){
		if(c == ' '){
			continue;
		}
		if(used[c]){
			return false;
		}
		used[c] = true;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "END"){
			break;
		}
		if(fridge(line)){
			cout << line << '\n';
		}
	}
	return 0;
}
