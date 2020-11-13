#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		cout << "Pairs for " << n << ':';
		for(int i = 1; 2 * i < n; ++i){
			if(i > 1){
				cout << ',';
			}
			cout << ' ' << i << ' ' << n - i;
		}
		cout << '\n';
	}
	return 0;
}
