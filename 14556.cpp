#include <iostream>

using namespace std;

int main(){
	long long mod = 1000000009LL;
	int n;
	cin >> n;
	long long ans = 1;
	for(int i = 1; i <= n; ++i){
		ans = ans * (2 * i - 1) % mod;
	}
	cout << ans << endl;
	return 0;
}
