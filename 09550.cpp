#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n, k;
		cin >> n >> k;
		int children = 0;
		for(int j = 0; j < n; ++j){
			int candy;
			cin >> candy;
			children += candy / k;
		}
		cout << children << '\n';
	}
	return 0;
}
