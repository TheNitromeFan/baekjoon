#include <iostream>
#include <string>

using namespace std;

char symbol(int val){
	char ret;
	switch(val){
		case 0:
			ret = ' ';
			break;
		case 27:
			ret = '\'';
			break;
		case 28:
			ret = ',';
			break;
		case 29:
			ret = '-';
			break;
		case 30:
			ret = '.';
			break;
		case 31:
			ret = '?';
			break;
		default:
			ret = val - 1 + 'A';
			break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "#"){
			break;
		}
		string bitstring = "";
		while(line != "*"){
			unsigned idx = 0;
			while(idx < line.length()){
				while(idx < line.length() && line[idx] != ' '){
					++idx;
				}
				if(idx == line.length()){
					break;
				}
				int spaces = 0;
				unsigned end = idx;
				while(end < line.length() && line[end] == ' '){
					++end;
					++spaces;
				}
				if(spaces % 2 == 1){
					bitstring += (char)0;
				}else{
					bitstring += (char)1;
				}
				idx = end;
			}
			getline(cin, line);
		}
		if(bitstring.length() % 5 != 0){
			bitstring += string(5 - bitstring.length() % 5, 0);
		}
		for(unsigned idx = 0; idx < bitstring.length(); idx += 5){
			cout << symbol(16 * bitstring[idx] + 8 * bitstring[idx + 1]
			+ 4 * bitstring[idx + 2] + 2 * bitstring[idx + 3] + bitstring[idx + 4]);
		}
		cout << '\n';
	}
	return 0;
}
