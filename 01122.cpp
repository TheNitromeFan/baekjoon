#include <iostream>

using namespace std;

bool flip_n_times(long long a, long long b, long long k, long long n){
	if(k * n < a){
		return false;
	}
	if(n % 2 == 0){
		return a % 2 == 0 && a <= (a + b - k) * n;
	}else{
		return a % 2 == k % 2 && b <= (a + b - k) * n;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b, k;
	cin >> a >> b >> k;
	for(long long n = 0; n <= 2 * (a + b); ++n){
		if(flip_n_times(a, b, k, n)){
			cout << n;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
