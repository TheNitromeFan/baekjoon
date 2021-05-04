#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	getline(cin, s);
	getline(cin, t);
	unsigned i = 0, j = 0;
	set<char> sticky;
	while(j < t.length()){
		if(i >= s.length() || s[i] != t[j]){
			sticky.insert(t[j]);
			++j;
		}else{
			++i;
			++j;
		}
	}
	for(char letter : sticky){
		cout << letter;
	}
	return 0;
}
