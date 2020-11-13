#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(){
	vector<int> v(3, 0);
	for(int i = 0; i < 3; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	map<char, int> m;
	m['A'] = v[0];
	m['B'] = v[1];
	m['C'] = v[2];
	string s;
	cin >> s;
	for(int i = 0; i < 3; ++i){
		cout << m[s[i]] << ' ';
	}
	return 0;
}
