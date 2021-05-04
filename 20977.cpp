#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> m = {{'J', -1}, {'O', 0}, {'I', 1}};
	sort(s.begin(), s.end(), [&m](char a, char b){
		return m[a] < m[b];
	});
	cout << s;
	return 0;
}
