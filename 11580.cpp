#include <iostream>
#include <string>
#include <set>
#include <utility>

using namespace std;

int main(){
	int n;
	string instr;
	cin >> n >> instr;
	pair<int, int> pos = make_pair(0, 0);
	set<pair<int, int>> s;
	s.insert(pos);
	for(char c : instr){
		switch(c){
			case 'S':
				--pos.second;
				break;
			case 'E':
				++pos.first;
				break;
			case 'N':
				++pos.second;
				break;
			case 'W':
				--pos.first;
				break;
		}
		s.insert(pos);
	}
	cout << s.size();
	return 0;
}
