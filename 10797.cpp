#include <iostream>

using std::cin;
using std::cout;

int main(){
	int day = 0;
	cin >> day;
	int car = 0, count = 0;
	for(int i = 0; i < 5; ++i){
		cin >> car;
		if(day == car)
			++count;
	}
	cout << count;
	return 0;
}
