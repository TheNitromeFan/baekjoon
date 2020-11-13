#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static char yut(int total){
	switch(total){
		case 3:
			return 'A';
		case 2:
			return 'B';
		case 1:
			return 'C';
		case 0:
			return 'D';
		default:
			return 'E';
	}
}

int main(){
	int stick = 0, total = 0;
	for(int i = 0; i < 3; ++i){
		total = 0;
		for(int j = 0; j < 4; ++j){
			cin >> stick;
			total += stick;
		}
		cout << yut(total) << endl;
	}
	return 0;
}
