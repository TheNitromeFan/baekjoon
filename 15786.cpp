#include <iostream>
#include <string>

using namespace std;

bool match(string s, string t){
	unsigned idx = 0;
	for(char c : t){
		if(s[idx] == c){
			++idx;
		}
		if(idx == s.length()){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string memory;
	cin >> memory;
	for(int i = 0; i < m; ++i){
		string sticky;
		cin >> sticky;
		if(match(memory, sticky)){
			cout << "true\n";
		}else{
			cout << "false\n";
		}
	}
	return 0;
}
