#include <iostream>
#include <string>

using namespace std;

int val(char c){
	if(c >= '0' && c <= '9'){
		return c - '0';
	}else if(c >= 'A' && c <= 'Z'){
		return c - 'A' + 10;
	}else{
		return c - 'a' + 10 + 26;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	while(true){
		cin >> line;
		if(line == "end"){
			break;
		}
		int checksum = 0;
		for(char c : line){
			checksum += val(c);
		}
		cout << (checksum % 61 == 0 ? "yes" : "no") << '\n';
	}
	return 0;
}
