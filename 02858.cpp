#include <iostream>
#include <cmath>

using namespace std;

int square_root(int n){
	int x = (int)sqrt(n);
	for(int i = x-2; i <= x+2; ++i){
		if(x * x == n){
			return x;
		}
	}
	return -1;
}

int main(){
	int r, b;
	cin >> r >> b;
	int d = (r - 4) * (r - 4) - 16 * b;
	cout << (r + 4 + square_root(d)) / 4 << ' ' << (r + 4 - square_root(d)) / 4;
	return 0;
}
