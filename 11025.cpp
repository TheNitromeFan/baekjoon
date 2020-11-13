#include <iostream>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int r = 1;
	for(int i = 2; i <= n; ++i){
		r = (r + k - 1) % i + 1;
	}
	cout << r;
	return 0;
}
