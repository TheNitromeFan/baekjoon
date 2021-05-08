#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, k;
	cin >> n >> k;
	long long q = n / k, r = n % k;
	long long x = 0, ans = 0;
	if(r == 0){
		ans = k;
	}else if((k - r) % (q + 1) == 0){
		x = (k - r) / (q + 1);
		ans = k - x;
	}else{
		x = (k - r) / (q + 1);
		ans = k - x - 1;
	}
	cout << ans;
	return 0;
}
