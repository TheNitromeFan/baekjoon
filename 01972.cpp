#include <iostream>
#include <string>
#include <utility>
#include <set>

using namespace std;

bool is_surprising(string &str){
	set<pair<char, char>> s;
	for(unsigned dist = 0; dist + 2 < str.length(); ++dist){
		s.clear();
		for(unsigned i = 0; i + dist + 1 < str.length(); ++i){
			pair<char, char> p = make_pair(str[i], str[i + dist + 1]);
			if(s.find(p) != s.end()){
				return false;
			}
			s.insert(p);
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string str;
		cin >> str;
		if(str == "*"){
			break;
		}
		if(is_surprising(str)){
			cout << str << " is surprising.\n";
		}else{
			cout << str << " is NOT surprising.\n";
		}
	}
	return 0;
}
