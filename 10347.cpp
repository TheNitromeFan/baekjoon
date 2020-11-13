#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		unsigned n;
		cin >> n;
		if(n == 0){
			break;
		}
		string line;
		cin >> line;
		reverse(line.begin(), line.end());
		for(char c : line){
			unsigned i = find(key.begin(), key.end(), c) - key.begin() + n;
			if(i >= key.length()){
				i -= key.length();
			}
			cout << key[i];
		}
		cout << '\n';
	}
	return 0;
}
