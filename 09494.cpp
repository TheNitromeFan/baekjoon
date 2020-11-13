#include <iostream>
#include <string>

using namespace std;

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		unsigned pos = 0;
		string line;
		getline(cin, line);
		for(int i = 0; i < n; ++i){
			getline(cin, line);
			while(pos < line.length() && line[pos] != ' '){
				++pos;
			}
		}
		cout << pos + 1 << '\n';
	}
	return 0;
}
