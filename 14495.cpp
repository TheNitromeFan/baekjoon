#include <iostream>

using namespace std;

int main(){
	long long f[117];
	f[1] = f[2] = f[3] = 1LL;
	int n;
	cin >> n;
	for(int i = 4; i <= n; ++i){
		f[i] = f[i-1] + f[i-3];
	}
	cout << f[n] << endl;
	return 0;
}
