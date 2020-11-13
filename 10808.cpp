#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main(){
	vector<int> count(26, 0);
	string s;
	cin >> s;
	for(char c : s)
		++count[static_cast<vector<int>::size_type>(c - 'a')];
	for(int num : count)
		cout << num << " ";
	return 0;
}
