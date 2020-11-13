#include <iostream>
#include <string>
#include <set>

using namespace std;

bool pangram(string str){
	set<char> s;
	for(char c : str){
		if(c != ' '){
			s.insert(c);
		}
	}
	return s.size() == 26;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "*"){
			break;
		}
		cout << (pangram(line) ? 'Y' : 'N') << '\n';
	}
	return 0;
}
