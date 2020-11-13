#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main(){
	set<char> s;
	vector<char> v;
	string field;
	cin >> field;
	int cnt = 0;
	for(char c : field){
		if(s.find(c) != s.end()){
			unsigned i;
			for(i = v.size() - 1; v[i] != c; --i){
				++cnt;
			}
			v.erase(v.begin() + i);
		}else{
			v.push_back(c);
			s.insert(c);
		}
	}
	cout << cnt;
	return 0;
}
