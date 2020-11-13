#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s;
	cin >> s;
	set<char> used;
	string line;
	getline(cin, line);
	for(int i = 0; i < s; ++i){
		getline(cin, line);
		for(char c : line){
			if(c != ' ' && used.find(c) == used.end()){
				used.insert(c);
				cout << c;
			}
		}
	}
	return 0;
}
