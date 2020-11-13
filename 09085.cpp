#include <iostream>

using std::cin;
using std::cout;

int main(){
	int t = 0;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n = 0;
		cin >> n;
		int sum = 0, num = 0;
		for(int j = 0; j < n; ++j){
			cin >> num;
			sum += num;
		}
		cout << sum << "\n";
	}
	return 0;
}
