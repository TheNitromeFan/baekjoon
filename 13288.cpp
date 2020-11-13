#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<string> sym(26, "");
	sym[0] = "@";
	sym[1] = "8";
	sym[2] = "(";
	sym[3] = "|)";
	sym[4] = "3";
	sym[5] = "#";
	sym[6] = "6";
	sym[7] = "[-]";
	sym[8] = "|";
	sym[9] = "_|";
	sym[10] = "|<";
	sym[11] = "1";
	sym[12] = "[]\\/[]";
	sym[13] = "[]\\[]";
	sym[14] = "0";
	sym[15] = "|D";
	sym[16] = "(,)";
	sym[17] = "|Z";
	sym[18] = "$";
	sym[19] = "']['";
	sym[20] = "|_|";
	sym[21] = "\\/";
	sym[22] = "\\/\\/";
	sym[23] = "}{";
	sym[24] = "`/";
	sym[25] = "2";
	string line;
	getline(cin, line);
	for(char c : line){
		if(c >= 'A' && c <= 'Z'){
			cout << sym[c - 'A'];
		}else if(c >= 'a' && c <= 'z'){
			cout << sym[c - 'a'];
		}else{
			cout << c;
		}
	}
	return 0;
}
