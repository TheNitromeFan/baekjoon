#include <iostream>
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long x = 0, y = 0;
	for(int i = 0; i < n - 1; ++i){
		long long mi;
		cin >> mi;
		y = (y + 1) * mi;
		y %= MOD;
		x += y;
		x %= MOD;
	}
	cout << x;
	return 0;
}
