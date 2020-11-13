#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::string;

static bool is_group(string s){
	int groups[26] = {};
	++groups[s[0] - 'a'];
	for(string::size_type i = 1; i < s.size(); ++i){
		if(s[i] != s[i-1]){
			++groups[s[i] - 'a'];
			if(groups[s[i] - 'a'] > 1)
				return false;
		}
	}
	return true;
}

int main(){
	int words = 0;
	cin >> words;
	string word;
	int count = 0;
	for(int w = 0; w < words; ++w){
		cin >> word;
		if(is_group(word))
			++count;
	}
	cout << count;
	return 0;
}
