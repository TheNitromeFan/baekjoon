#include <iostream>
#include <string>

using namespace std;

int main(){
	string ab;
	cin >> ab;
	switch(ab.length()){
		case 2:
			cout << (ab[0] - '0') + (ab[1] - '0');
			break;
		case 3:
			if(ab[1] == '0'){
				cout << 10 + (ab[2] - '0');
			}else{
				cout << (ab[0] - '0') + 10;
			}
			break;
		case 4:
			cout << 20;
			break;
	}
	return 0;
}
