#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		string s;
		cin >> s;
		list<char> li;
		for(char c : s){
			li.push_back(c);
		}
		while(true){
			string command;
			cin >> command;
			if(command == "END"){
				break;
			}else if(command == "I"){
				string r;
				unsigned x;
				cin >> r >> x;
				list<char>::iterator it = li.begin();
				advance(it, x);
				for(char c : r){
					li.insert(it, c);
				}
			}else if(command == "P"){
				unsigned x, y;
				cin >> x >> y;
				list<char>::iterator it = li.begin();
				advance(it, x);
				for(unsigned i = 0; i < y - x + 1; ++i){
					cout << *it;
					++it;
				}
				cout << '\n';
			}
		}
	}
	return 0;
}
