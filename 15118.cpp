#include <iostream>
#include <cmath>

using namespace std;

long long long_long_sqrt(long long x){
	long long i = sqrt(x) - 3;
	for(; i * i <= x; ++i);
	return i - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	cout << (2 * n - 1 - long_long_sqrt(2 * n * n - 2 * n + 1) - 1) / 2 + 1;
	return 0;
}
