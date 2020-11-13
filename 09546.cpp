#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int k;
		cin >> k;
		cout << (1 << k) - 1 << '\n';
	}
	return 0;
}
