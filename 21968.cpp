#include <iostream>

using namespace std;

long long f(long long n){
	long long pow3 = 1;
	long long ans = 0;
	while(n){
		if(n % 2){
			ans += pow3;
		}
		n /= 2;
		pow3 *= 3;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long n;
		cin >> n;
		cout << f(n) << '\n';
	}
	return 0;
}
