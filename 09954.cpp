#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "#"){
			break;
		}
		char key = line[line.length() - 1];
		for(unsigned idx = 0; idx < line.length() - 1; ++idx){
			char c = line[idx];
			if(c >= 'A' && c <= 'Z'){
				c -= key - 'A';
				if(c < 'A'){
					c += 26;
				}
			}else if(c >= 'a' && c <= 'z'){
				c -= key - 'A';
				if(c < 'a'){
					c += 26;
				}
			}
			cout << c;
		}
		cout << '\n';
	}
	return 0;
}
