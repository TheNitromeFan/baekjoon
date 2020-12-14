#include <iostream>
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d;
	cin >> d;
	long long num = 0, x = 0, factorial = 1;
	for(int i = 1; i <= d; ++i){
		int di;
		cin >> di;
		num += factorial - x + x * i + di - 1;
		x = x * i + di - 1;
		factorial *= i;
		num %= MOD;
		factorial %= MOD;
		x %= MOD;
		cout << num << '\n';
	}
	return 0;
}
