#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::string;

static string pattern(size_t n, string names[50]){
	string ret = names[0];
	for(size_t j = 0; j < names[0].size(); ++j){
		for(size_t i = 1; i < n; ++i){
			if(names[i][j] != names[0][j]){
				ret[j] = '?';
				break;
			}
		}
	}
	return ret;
}

int main(){
	size_t n = 0;
	string files[50];
	cin >> n;
	for(size_t i = 0; i < n; ++i)
		cin >> files[i];
	cout << pattern(n, files);
	return 0;
}
