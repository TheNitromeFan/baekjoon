#include <iostream>

using namespace std;

int main(){
	int total = 0, a;
	for(int i = 0; i < 4; ++i){
		cin >> a;
		total += a;
	}
	cout << total / 60 << '\n' << total % 60;
	return 0;
}
