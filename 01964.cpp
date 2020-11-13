#include <iostream>

using namespace std;

int main(){
	long long n;
	cin >> n;
	cout << ((3*n + 5) * n / 2 + 1) % 45678;
	return 0;
}
