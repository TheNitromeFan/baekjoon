#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int d = 1;
	while(n % d == 0){
		++d;
	}
	cout << d << ' ' << n - 1;
	return 0;
}
