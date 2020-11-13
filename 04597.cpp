#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		cin >> line;
		if(line == "#"){
			break;
		}
		int ones = 0;
		for(char c : line){
			if(c == '1'){
				++ones;
			}
		}
		if(line[line.length() - 1] == 'e'){
			line[line.length() - 1] = (ones % 2) ? '1' : '0';
		}else{
			line[line.length() - 1] = (ones % 2) ? '0' : '1';
		}
		cout << line << '\n';
	}
	return 0;
}
